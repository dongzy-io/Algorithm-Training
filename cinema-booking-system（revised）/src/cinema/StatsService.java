package cinema;

import java.time.LocalDate;
import java.util.*;

/** Revenue, box office and occupancy statistics (reads the incremental Ledger). */
public class StatsService {
    private final CinemaSystem sys;
    private final BookingService booking;
    public StatsService(CinemaSystem sys, BookingService booking) { this.sys = sys; this.booking = booking; }

    public record ScreeningRow(Screening s, double normalPrice, double vipPrice, int sold, int capacity,
                               double occupancy, double revenue) {}
    public record MovieRow(Movie movie, int tickets, double revenue) {}
    public record CinemaRow(Cinema cinema, double revenue, int sold, int capacity, double occupancy) {}

    /** Per-screening figures; hall == null means all halls, date == null means all dates. */
    public List<ScreeningRow> screeningRows(Hall hall, LocalDate date) {
        List<ScreeningRow> rows = new ArrayList<>();
        for (Screening s : sys.getScreenings()) {
            if (hall != null && s.getHall().getId() != hall.getId()) continue;
            if (date != null && !s.getStart().toLocalDate().equals(date)) continue;
            double[] pr = booking.adultPrices(s);
            rows.add(new ScreeningRow(s, pr[0], pr[1], s.soldCount(), s.getHall().capacity(), s.occupancyRate(),
                    sys.getLedger().screeningRevenue(s.getId())));
        }
        return rows;
    }

    public double hallRevenue(Hall h) { return sys.getLedger().hallRevenue(h.getId()); }

    public double cinemaRevenue(Cinema c) {
        double sum = 0;
        for (Hall h : c.getHalls()) sum += hallRevenue(h);
        return Math.round(sum * 100) / 100.0;
    }

    /** Box office of every movie. */
    public List<MovieRow> movieRows() {
        List<MovieRow> rows = new ArrayList<>();
        for (Movie m : sys.getMovies())
            rows.add(new MovieRow(m, sys.getLedger().movieTickets(m.getId()), sys.getLedger().movieRevenue(m.getId())));
        return rows;
    }

    /** Top-K highest grossing movies (min-heap based). */
    public List<MovieRow> topMovies(int k) {
        return Algorithms.topK(movieRows(), k, Comparator.comparingDouble(MovieRow::revenue));
    }

    /** Occupancy and revenue per cinema, one entry for every cinema. */
    public List<CinemaRow> cinemaRows() {
        Map<Integer, int[]> seats = new HashMap<>();         // cinema id -> {sold, capacity}
        for (Screening s : sys.getScreenings()) {
            int[] a = seats.computeIfAbsent(s.getHall().getCinemaId(), k -> new int[2]);
            a[0] += s.soldCount();
            a[1] += s.getHall().capacity();
        }
        List<CinemaRow> rows = new ArrayList<>();
        for (Cinema c : sys.getCinemas()) {
            int[] a = seats.getOrDefault(c.getId(), new int[2]);
            rows.add(new CinemaRow(c, cinemaRevenue(c), a[0], a[1], a[1] == 0 ? 0 : 100.0 * a[0] / a[1]));
        }
        return rows;
    }

    /** Cinemas ranked by occupancy (top K). */
    public List<CinemaRow> topCinemasByOccupancy(int k) {
        return Algorithms.topK(cinemaRows(), k, Comparator.comparingDouble(CinemaRow::occupancy));
    }
}
