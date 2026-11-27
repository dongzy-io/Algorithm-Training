package cinema;

import java.time.LocalDateTime;
import java.util.*;

/** Pricing, booking, refunding, seat recommendation and ticket queries. */
public class BookingService {
    /** Early-bird coefficient for shows that start before 12:00. */
    public static final double EARLY_RATE = 0.8;
    /** A refund is possible up to this many minutes before the show starts. */
    public static final int REFUND_DEADLINE_MIN = 30;

    private final CinemaSystem sys;
    public BookingService(CinemaSystem sys) { this.sys = sys; }

    /**
     * Price = movie base price * hall type rate, then the seat decides its own coefficient
     * (polymorphism), then * ticket type rate * early-bird rate.
     */
    public double price(Screening s, Seat seat, TicketType type) {
        double base = s.getMovie().getBasePrice() * s.getHall().getType().getRate();
        double p = seat.priceFor(base) * type.getRate();
        if (s.getStart().getHour() < 12) p *= EARLY_RATE;
        return Math.round(p * 100) / 100.0;
    }
    /** Adult prices of a screening: {normal seat, VIP seat}. */
    public double[] adultPrices(Screening s) {
        return new double[]{price(s, new NormalSeat(0, 0), TicketType.ADULT), price(s, new VipSeat(0, 0), TicketType.ADULT)};
    }

    /**
     * Books several seats at once ({row, col}, 0-based). All seats are validated first, tickets are
     * issued only if every seat is valid, so the operation is atomic.
     */
    public List<Ticket> book(int screeningId, List<int[]> seatList, String buyer, TicketType type) throws CinemaException {
        Screening s = sys.getScreening(screeningId);
        if (!s.getStart().isAfter(sys.getNow()))
            throw new BookingClosedException("Screening #" + s.getId() + " has already started (" + Fmt.dt(s.getStart()) + ")");
        if (buyer == null || buyer.trim().isEmpty()) throw new InvalidInputException("Buyer name must not be empty");
        if (seatList.isEmpty()) throw new InvalidInputException("Select at least one seat");
        Hall h = s.getHall();
        Set<Integer> seen = new HashSet<>();
        for (int[] p : seatList) {
            int r = p[0], c = p[1];
            if (r < 0 || r >= h.getRows() || c < 0 || c >= h.getCols())
                throw new InvalidSeatException("Seat row " + (r + 1) + " seat " + (c + 1) + " does not exist (hall has "
                        + h.getRows() + " rows x " + h.getCols() + " seats)");
            if (!seen.add(r * h.getCols() + c))
                throw new InvalidSeatException("Seat row " + (r + 1) + " seat " + (c + 1) + " was selected twice");
            if (s.isSold(r, c))
                throw new SeatOccupiedException("Seat row " + (r + 1) + " seat " + (c + 1) + " is already sold");
        }
        List<Ticket> res = new ArrayList<>();
        for (int[] p : seatList) {
            Ticket t = new Ticket(sys.newTicketId(), s.getId(), p[0], p[1], buyer.trim(), type, price(s, h.getSeat(p[0], p[1]), type));
            s.occupy(p[0], p[1]);
            sys.putTicket(t);
            sys.getLedger().recordSale(s, t);
            res.add(t);
        }
        return res;
    }

    /** Refund: only before REFUND_DEADLINE_MIN minutes ahead of the start; frees the seat and the revenue. */
    public Ticket refund(int ticketId) throws CinemaException {
        Ticket t = sys.getTicket(ticketId);
        if (t.isRefunded()) throw new CinemaException("Ticket " + ticketId + " has already been refunded");
        Screening s = sys.getScreening(t.getScreeningId());
        LocalDateTime deadline = s.getStart().minusMinutes(REFUND_DEADLINE_MIN);
        if (sys.getNow().isAfter(deadline))
            throw new RefundNotAllowedException("Refund deadline passed (" + Fmt.dt(deadline) + "); refunds close "
                    + REFUND_DEADLINE_MIN + " minutes before the show");
        s.release(t.getRow(), t.getCol());
        t.setRefunded(true);
        sys.getLedger().recordRefund(s, t);
        return t;
    }

    public List<Algorithms.SeatGroup> recommend(Screening s, int people, int topN) throws InvalidInputException {
        if (people < 1 || people > s.getHall().getCols())
            throw new InvalidInputException("Group size must be between 1 and " + s.getHall().getCols());
        return Algorithms.recommend(s, people, topN);
    }

    public List<Ticket> ticketsByMovieKeyword(String keyword) throws NotFoundException {
        List<Ticket> res = new ArrayList<>();
        String k = keyword.toLowerCase();
        for (Ticket t : sys.getTickets())
            if (sys.getScreening(t.getScreeningId()).getMovie().getName().toLowerCase().contains(k)) res.add(t);
        return res;
    }
    public List<Ticket> ticketsByBuyer(String buyer) {
        List<Ticket> res = new ArrayList<>();
        for (Ticket t : sys.getTickets()) if (t.getBuyer().equalsIgnoreCase(buyer)) res.add(t);
        return res;
    }
}
