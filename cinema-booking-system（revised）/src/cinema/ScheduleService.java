package cinema;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.*;

/** Movies, screenings and every search that is based on time (timetables, status at a moment, ...). */
public class ScheduleService {
    private final CinemaSystem sys;
    public ScheduleService(CinemaSystem sys) { this.sys = sys; }

    /** State of one hall at a given moment. state is PLAYING, CLEANING or IDLE. */
    public record HallStatus(Cinema cinema, Hall hall, String state, Screening current, Screening next) {}

    public Movie addMovie(String name, int duration, double basePrice) throws InvalidInputException {
        if (name == null || name.trim().isEmpty()) throw new InvalidInputException("Movie name must not be empty");
        if (duration < 30 || duration > 300) throw new InvalidInputException("Duration must be between 30 and 300 minutes");
        if (basePrice <= 0) throw new InvalidInputException("Base price must be positive");
        Movie m = new Movie(sys.newMovieId(), name.trim(), duration, basePrice);
        sys.addMovie(m);
        return m;
    }

    /**
     * Adds a screening. Checks: start time is in the future, inside business hours, and does not
     * conflict (cleaning gap included) with another screening of the same hall.
     */
    public Screening addScreening(int movieId, int hallId, LocalDateTime start) throws CinemaException {
        Movie m = sys.getMovie(movieId);
        Hall h = sys.getHall(hallId);
        if (!start.isAfter(sys.getNow()))
            throw new InvalidInputException("Start time must be later than the current time (" + Fmt.dt(sys.getNow()) + ")");
        if (!Algorithms.insideBusinessHours(start, m.getDurationMin()))
            throw new InvalidInputException("Screening must start at or after " + Algorithms.OPEN_HOUR
                    + ":00 and end before midnight");
        LocalDateTime end = start.plusMinutes(m.getDurationMin());
        Screening conflict = Algorithms.findConflict(sys.scheduleOf(h), start, end);
        if (conflict != null)
            throw new ScheduleConflictException("Conflicts with screening #" + conflict.getId() + " "
                    + conflict.getMovie() + " (" + Fmt.dt(conflict.getStart()) + " - " + Fmt.time(conflict.end())
                    + ", plus " + Algorithms.GAP_MIN + " min cleaning) in " + h.getName());
        Screening s = new Screening(sys.newScreeningId(), m, h, start);
        sys.insertScreening(s);
        return s;
    }

    /** Earliest time at which the movie can start in the hall, not before 'earliest'. */
    public LocalDateTime earliestSlot(Movie m, Hall h, LocalDateTime earliest) {
        return Algorithms.earliestSlot(sys.scheduleOf(h), earliest, m.getDurationMin());
    }

    /** Screenings of a hall that start in [from, to): two binary searches on the sorted list. */
    public List<Screening> hallRange(Hall h, LocalDateTime from, LocalDateTime to) {
        List<Screening> list = sys.scheduleOf(h);
        return list.subList(Algorithms.lowerBound(list, from), Algorithms.lowerBound(list, to));
    }

    /** Seven-day timetable of a hall starting at the given date, grouped by day. */
    public Map<LocalDate, List<Screening>> weeklyTimetable(Hall h, LocalDate from) {
        Map<LocalDate, List<Screening>> week = new TreeMap<>();
        for (int d = 0; d < 7; d++) {
            LocalDate day = from.plusDays(d);
            week.put(day, hallRange(h, day.atStartOfDay(), day.plusDays(1).atStartOfDay()));
        }
        return week;
    }

    /** Screenings (all cinemas) that start on the given date. */
    public List<Screening> onDate(LocalDate d) {
        List<Screening> all = sys.getScreenings();
        return all.subList(Algorithms.lowerBound(all, d.atStartOfDay()), Algorithms.lowerBound(all, d.plusDays(1).atStartOfDay()));
    }

    /** Movies whose name contains the keyword (case-insensitive). */
    public List<Movie> findMovies(String keyword) {
        List<Movie> res = new ArrayList<>();
        String k = keyword.toLowerCase();
        for (Movie m : sys.getMovies()) if (m.getName().toLowerCase().contains(k)) res.add(m);
        return res;
    }

    /** Screenings of a movie starting at or after 'from', using the per-movie sorted index. */
    public List<Screening> upcomingOfMovie(Movie m, LocalDateTime from) {
        List<Screening> list = sys.screeningsOfMovie(m);
        return list.subList(Algorithms.lowerBound(list, from), list.size());
    }

    /** What is every hall doing at time t? One binary search per hall. */
    public List<HallStatus> statusAt(LocalDateTime t) throws NotFoundException {
        List<HallStatus> res = new ArrayList<>();
        for (Hall h : sys.getHalls()) {
            List<Screening> sched = sys.scheduleOf(h);
            int k = Algorithms.floorIndex(sched, t);
            Cinema c = sys.cinemaOf(h);
            Screening next = k + 1 < sched.size() ? sched.get(k + 1) : null;
            if (k >= 0) {
                Screening cur = sched.get(k);
                if (t.isBefore(cur.end())) { res.add(new HallStatus(c, h, "PLAYING", cur, next)); continue; }
                if (t.isBefore(cur.end().plusMinutes(Algorithms.GAP_MIN))) { res.add(new HallStatus(c, h, "CLEANING", cur, next)); continue; }
            }
            res.add(new HallStatus(c, h, "IDLE", null, next));
        }
        return res;
    }

    // ------------------------------------------------------------------ week cycle and three-way queries

    /** First day of the current week: weeks are 7-day blocks counted from the system's week base and follow the clock. */
    public LocalDate weekStart() {
        long days = ChronoUnit.DAYS.between(sys.getWeekBase(), sys.getNow().toLocalDate());
        return sys.getWeekBase().plusDays(days > 0 ? days / 7 * 7 : 0);
    }
    public LocalDateTime weekFrom() { return weekStart().atStartOfDay(); }
    /** Exclusive end of the current week. */
    public LocalDateTime weekTo() { return weekStart().plusDays(7).atStartOfDay(); }

    private static final Comparator<Screening> BY_TIME =
            Comparator.comparing(Screening::getStart).thenComparingInt(s -> s.getHall().getId());

    /** Query 1 (cinema + time slot): every screening of every hall of the cinema that starts in [from, to). */
    public List<Screening> inCinema(Cinema c, LocalDateTime from, LocalDateTime to) {
        List<Screening> res = new ArrayList<>();
        for (Hall h : c.getHalls()) res.addAll(hallRange(h, from, to));
        res.sort(BY_TIME);
        return res;
    }

    /** Screenings of a movie (all cinemas) that start in [from, to), from the per-movie sorted index. */
    public List<Screening> ofMovie(Movie m, LocalDateTime from, LocalDateTime to) {
        List<Screening> list = sys.screeningsOfMovie(m);
        List<Screening> res = new ArrayList<>(list.subList(Algorithms.lowerBound(list, from), Algorithms.lowerBound(list, to)));
        res.sort(BY_TIME);
        return res;
    }

    /** Query 2 (cinema + movie): screenings of the movie in this cinema that start in [from, to). */
    public List<Screening> ofMovieInCinema(Cinema c, Movie m, LocalDateTime from, LocalDateTime to) {
        List<Screening> res = new ArrayList<>();
        for (Screening s : ofMovie(m, from, to)) if (s.getHall().getCinemaId() == c.getId()) res.add(s);
        return res;
    }

    /** Query 3 (time slot + movie): cinemas (in id order) that show the movie in [from, to), with their screenings. */
    public Map<Cinema, List<Screening>> ofMovieByCinema(Movie m, LocalDateTime from, LocalDateTime to) {
        Map<Integer, List<Screening>> byId = new HashMap<>();
        for (Screening s : ofMovie(m, from, to)) byId.computeIfAbsent(s.getHall().getCinemaId(), k -> new ArrayList<>()).add(s);
        Map<Cinema, List<Screening>> res = new LinkedHashMap<>();
        for (Cinema c : sys.getCinemas()) if (byId.containsKey(c.getId())) res.put(c, byId.get(c.getId()));
        return res;
    }
}
