package cinema;

/** Thrown when booking a screening that has already started. */
public class BookingClosedException extends CinemaException {
    public BookingClosedException(String message) { super(message); }
}
