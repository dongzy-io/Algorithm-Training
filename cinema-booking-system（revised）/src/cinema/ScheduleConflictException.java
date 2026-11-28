package cinema;

/** Thrown when a new screening overlaps another one in the same hall. */
public class ScheduleConflictException extends CinemaException {
    public ScheduleConflictException(String message) { super(message); }
}
