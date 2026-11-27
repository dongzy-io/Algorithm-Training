package cinema;

/** Base class of all checked business exceptions in the system. */
public class CinemaException extends Exception {
    public CinemaException(String message) { super(message); }
}
