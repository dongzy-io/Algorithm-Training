package cinema;

/** Thrown when an entity cannot be found by id. */
public class NotFoundException extends CinemaException {
    public NotFoundException(String message) { super(message); }
}
