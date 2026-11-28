package cinema;

/** Thrown when a seat is out of range or selected twice. */
public class InvalidSeatException extends CinemaException {
    public InvalidSeatException(String message) { super(message); }
}
