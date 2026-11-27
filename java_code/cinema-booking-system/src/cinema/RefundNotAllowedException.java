package cinema;

/** Thrown when a refund is requested too close to the start time. */
public class RefundNotAllowedException extends CinemaException {
    public RefundNotAllowedException(String message) { super(message); }
}
