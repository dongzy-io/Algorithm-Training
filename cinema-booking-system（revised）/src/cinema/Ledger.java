package cinema;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

/**
 * Running revenue counters. They are updated incrementally when a ticket is sold or refunded,
 * so reading the revenue of a hall / movie / screening is O(1) instead of scanning all tickets.
 */
public class Ledger implements Serializable {
    private static final long serialVersionUID = 1L;
    private final Map<Integer, Double> hallRevenue = new HashMap<>();
    private final Map<Integer, Double> movieRevenue = new HashMap<>();
    private final Map<Integer, Double> screeningRevenue = new HashMap<>();
    private final Map<Integer, Integer> movieTickets = new HashMap<>();

    private static double round2(double v) { return Math.round(v * 100) / 100.0; }

    private void apply(Screening s, double amount, int ticketDelta) {
        hallRevenue.merge(s.getHall().getId(), amount, (a, b) -> round2(a + b));
        movieRevenue.merge(s.getMovie().getId(), amount, (a, b) -> round2(a + b));
        screeningRevenue.merge(s.getId(), amount, (a, b) -> round2(a + b));
        movieTickets.merge(s.getMovie().getId(), ticketDelta, Integer::sum);
    }
    public void recordSale(Screening s, Ticket t) { apply(s, t.getPrice(), 1); }
    public void recordRefund(Screening s, Ticket t) { apply(s, -t.getPrice(), -1); }

    public double hallRevenue(int hallId) { return hallRevenue.getOrDefault(hallId, 0.0); }
    public double movieRevenue(int movieId) { return movieRevenue.getOrDefault(movieId, 0.0); }
    public double screeningRevenue(int screeningId) { return screeningRevenue.getOrDefault(screeningId, 0.0); }
    public int movieTickets(int movieId) { return movieTickets.getOrDefault(movieId, 0); }
}
