package cinema;

import java.time.LocalDateTime;
import java.util.*;

/**
 * Self-check program: compares the fast algorithms and the incremental ledger with simple,
 * obviously-correct brute-force versions on the sample data and on random inputs.
 * Run: java -cp out cinema.SelfCheck   (after compiling test/cinema/SelfCheck.java into out)
 */
public class SelfCheck {
    static int passed = 0, failed = 0;

    static void check(String name, boolean ok) {
        if (ok) passed++; else { failed++; System.out.println("FAIL: " + name); }
    }

    public static void main(String[] args) throws Exception {
        CinemaSystem sys = SampleData.build();
        BookingService booking = new BookingService(sys);
        Random rnd = new Random(2026);

        // 1. ledger and bit-sets agree with a plain scan of all tickets (also after random refunds)
        List<Ticket> all = new ArrayList<>(sys.getTickets());
        for (int i = 0; i < 200; i++) {
            Ticket t = all.get(rnd.nextInt(all.size()));
            if (!t.isRefunded()) booking.refund(t.getId());
        }
        Map<Integer, Double> hallRev = new HashMap<>();
        Map<Integer, Integer> movieCnt = new HashMap<>();
        Map<Integer, Integer> soldPerScreening = new HashMap<>();
        for (Ticket t : sys.getTickets()) {
            if (t.isRefunded()) continue;
            Screening s = sys.getScreening(t.getScreeningId());
            hallRev.merge(s.getHall().getId(), t.getPrice(), Double::sum);
            movieCnt.merge(s.getMovie().getId(), 1, Integer::sum);
            soldPerScreening.merge(s.getId(), 1, Integer::sum);
        }
        for (Hall h : sys.getHalls())
            check("hall revenue " + h.getId(), Math.abs(hallRev.getOrDefault(h.getId(), 0.0) - sys.getLedger().hallRevenue(h.getId())) < 0.01);
        for (Movie m : sys.getMovies())
            check("movie tickets " + m.getId(), movieCnt.getOrDefault(m.getId(), 0) == sys.getLedger().movieTickets(m.getId()));
        for (Screening s : sys.getScreenings())
            check("bitset count " + s.getId(), soldPerScreening.getOrDefault(s.getId(), 0) == s.soldCount());

        // 2. seat recommendation: same best scores as brute force; every option is free and contiguous
        for (int trial = 0; trial < 300; trial++) {
            Screening s = sys.getScreenings().get(rnd.nextInt(sys.getScreenings().size()));
            Hall h = s.getHall();
            int k = 1 + rnd.nextInt(Math.min(6, h.getCols()));
            List<Double> brute = new ArrayList<>();
            for (int r = 0; r < h.getRows(); r++)
                for (int st = 0; st + k <= h.getCols(); st++) {
                    boolean free = true;
                    for (int c = st; c < st + k; c++) if (s.isSold(r, c)) free = false;
                    if (!free) continue;
                    double score = Math.abs(st + (k - 1) / 2.0 - (h.getCols() - 1) / 2.0) + 1.5 * Math.abs(r - (h.getRows() - 1) * 0.6);
                    boolean leftFrag = st - 1 >= 0 && !s.isSold(r, st - 1) && (st - 2 < 0 || s.isSold(r, st - 2));
                    boolean rightFrag = st + k < h.getCols() && !s.isSold(r, st + k) && (st + k + 1 >= h.getCols() || s.isSold(r, st + k + 1));
                    if (leftFrag) score += 3;
                    if (rightFrag) score += 3;
                    brute.add(score);
                }
            Collections.sort(brute);
            List<Algorithms.SeatGroup> rec = Algorithms.recommend(s, k, 3);
            check("recommend count", rec.size() == Math.min(3, brute.size()));
            for (int i = 0; i < rec.size(); i++) {
                check("recommend score " + i, Math.abs(rec.get(i).score - brute.get(i)) < 1e-9);
                boolean free = true;
                for (int c = 0; c < k; c++) if (s.isSold(rec.get(i).row, rec.get(i).startCol + c)) free = false;
                check("recommend free", free);
            }
        }

        // 3. conflict detection and earliest slot against brute force
        Hall hall = sys.getHalls().get(0);
        List<Screening> sched = sys.scheduleOf(hall);
        LocalDateTime base = SampleData.FIRST_DAY.atStartOfDay();
        for (int trial = 0; trial < 400; trial++) {
            LocalDateTime t = base.plusMinutes(rnd.nextInt(8 * 24 * 60));
            int dur = 60 + rnd.nextInt(120);
            check("conflict", (Algorithms.findConflict(sched, t, t.plusMinutes(dur)) != null) == bruteConflict(sched, t, dur));
        }
        for (int trial = 0; trial < 60; trial++) {
            LocalDateTime t = base.plusMinutes(rnd.nextInt(6 * 24 * 60));
            int dur = 60 + rnd.nextInt(120);
            LocalDateTime expect = t;
            while (!(Algorithms.insideBusinessHours(expect, dur) && !bruteConflict(sched, expect, dur))) expect = expect.plusMinutes(1);
            check("earliest slot", Algorithms.earliestSlot(sched, t, dur).equals(expect));
        }

        // 4. binary searches
        for (int trial = 0; trial < 300; trial++) {
            LocalDateTime t = base.plusMinutes(rnd.nextInt(9 * 24 * 60));
            List<Screening> all2 = sys.getScreenings();
            int lb = 0; while (lb < all2.size() && all2.get(lb).getStart().isBefore(t)) lb++;
            int fl = -1; for (int i = 0; i < all2.size(); i++) if (!all2.get(i).getStart().isAfter(t)) fl = i;
            check("lowerBound", Algorithms.lowerBound(all2, t) == lb);
            check("floorIndex", Algorithms.floorIndex(all2, t) == fl);
        }

        // 5. top-K against sorting
        for (int trial = 0; trial < 200; trial++) {
            int n = rnd.nextInt(30), k = 1 + rnd.nextInt(6);
            List<Integer> data = new ArrayList<>();
            for (int i = 0; i < n; i++) data.add(rnd.nextInt(50));
            List<Integer> sorted = new ArrayList<>(data);
            sorted.sort(Comparator.reverseOrder());
            check("topK", Algorithms.topK(data, k, Comparator.naturalOrder()).equals(sorted.subList(0, Math.min(k, n))));
        }

        // 6. grid BFS: distance to the nearest cinema from every walkable cell, against relaxation
        City city = sys.getCity();
        int R = city.getRows(), C = city.getCols(), INF = 1 << 29;
        int[][] d = new int[R][C];
        for (int[] row : d) Arrays.fill(row, INF);
        for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) if (city.cinemaIdAt(r, c) > 0) d[r][c] = 0;
        boolean changed = true;
        while (changed) {
            changed = false;
            for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
                if (!city.isWalkable(r, c)) continue;
                int[][] nb = {{r - 1, c}, {r + 1, c}, {r, c - 1}, {r, c + 1}};
                for (int[] q : nb)
                    if (city.isWalkable(q[0], q[1]) && d[q[0]][q[1]] + 1 < d[r][c]) { d[r][c] = d[q[0]][q[1]] + 1; changed = true; }
            }
        }
        for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
            if (!city.isWalkable(r, c)) continue;
            List<Algorithms.GridHit> hit = Algorithms.bfsNearest(city.getGrid(), City.BLOCKED, r, c, (x, y) -> city.cinemaIdAt(x, y) > 0, 1);
            check("bfs " + r + "," + c, !hit.isEmpty() && hit.get(0).dist == d[r][c] && hit.get(0).path.size() == d[r][c] + 1);
        }

        // 4. weekly three-way queries agree with brute-force scans on random time slots
        ScheduleService weekSched = new ScheduleService(sys);
        for (int i = 0; i < 300; i++) {
            LocalDateTime from = SampleData.FIRST_DAY.atStartOfDay().plusMinutes(rnd.nextInt(7 * 24 * 60));
            LocalDateTime to = from.plusMinutes(1 + rnd.nextInt(3 * 24 * 60));
            Cinema c = sys.getCinemas().get(rnd.nextInt(sys.getCinemas().size()));
            Movie m = sys.getMovies().get(rnd.nextInt(sys.getMovies().size()));
            Set<Integer> q1 = new TreeSet<>(), q2 = new TreeSet<>(), q3 = new TreeSet<>();
            for (Screening s : sys.getScreenings()) {
                boolean in = !s.getStart().isBefore(from) && s.getStart().isBefore(to);
                if (!in) continue;
                if (s.getHall().getCinemaId() == c.getId()) q1.add(s.getId());
                if (s.getHall().getCinemaId() == c.getId() && s.getMovie().getId() == m.getId()) q2.add(s.getId());
                if (s.getMovie().getId() == m.getId()) q3.add(s.getId());
            }
            List<Screening> a = weekSched.inCinema(c, from, to);
            check("cinema+time " + i, ids(a).equals(q1) && sortedByTime(a));
            List<Screening> b = weekSched.ofMovieInCinema(c, m, from, to);
            check("cinema+movie " + i, ids(b).equals(q2) && sortedByTime(b));
            Set<Integer> got = new TreeSet<>();
            boolean ok = true;
            for (Map.Entry<Cinema, List<Screening>> e : weekSched.ofMovieByCinema(m, from, to).entrySet()) {
                for (Screening s : e.getValue()) { got.add(s.getId()); ok &= s.getHall().getCinemaId() == e.getKey().getId(); }
            }
            check("movie+time " + i, ok && got.equals(q3));
        }
        // 5. week cycle: 7-day blocks counted from the week base, following the clock
        sys.setNow(SampleData.FIRST_DAY.atTime(8, 0));
        check("week 1", weekSched.weekStart().equals(SampleData.FIRST_DAY));
        sys.setNow(SampleData.FIRST_DAY.plusDays(6).atTime(23, 59));
        check("week 1 last day", weekSched.weekStart().equals(SampleData.FIRST_DAY));
        sys.setNow(SampleData.FIRST_DAY.plusDays(7).atTime(0, 0));
        check("week 2", weekSched.weekStart().equals(SampleData.FIRST_DAY.plusDays(7)));
        sys.setNow(SampleData.FIRST_DAY.minusDays(3).atTime(9, 0));
        check("before week 1", weekSched.weekStart().equals(SampleData.FIRST_DAY));
        // 6. tickets of a time slot
        Ticket probe = sys.getTickets().iterator().next();
        LocalDateTime st = sys.getScreening(probe.getScreeningId()).getStart();
        check("tickets in slot", booking.ticketsInRange(probe.getBuyer(), st, st.plusMinutes(1)).contains(probe));
        check("tickets outside slot", !booking.ticketsInRange(probe.getBuyer(), st.plusMinutes(1), st.plusDays(1)).contains(probe));

        System.out.println("Self-check finished: " + passed + " passed, " + failed + " failed.");
        if (failed > 0) System.exit(1);
    }

    static boolean bruteConflict(List<Screening> sched, LocalDateTime start, int dur) {
        LocalDateTime end = start.plusMinutes(dur);
        for (Screening s : sched)
            if (start.isBefore(s.end().plusMinutes(Algorithms.GAP_MIN)) && s.getStart().isBefore(end.plusMinutes(Algorithms.GAP_MIN))) return true;
        return false;
    }

    static Set<Integer> ids(List<Screening> list) {
        Set<Integer> r = new TreeSet<>();
        for (Screening s : list) r.add(s.getId());
        return r;
    }
    static boolean sortedByTime(List<Screening> list) {
        for (int i = 1; i < list.size(); i++) if (list.get(i - 1).getStart().isAfter(list.get(i).getStart())) return false;
        return true;
    }
}
