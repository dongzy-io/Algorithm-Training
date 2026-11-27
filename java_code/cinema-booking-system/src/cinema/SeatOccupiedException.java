package cinema;

/** Thrown when a requested seat is already sold. */
public class SeatOccupiedException extends CinemaException {
    public SeatOccupiedException(String message) { super(message); }
}
