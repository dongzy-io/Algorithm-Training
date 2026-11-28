package cinema;

/** Thrown when user input has a wrong format or an illegal value. */
public class InvalidInputException extends CinemaException {
    public InvalidInputException(String message) { super(message); }
}
