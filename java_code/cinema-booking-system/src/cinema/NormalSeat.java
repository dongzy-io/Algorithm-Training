package cinema;

/** Ordinary seat: pays the base price. */
public class NormalSeat extends Seat {
    private static final long serialVersionUID = 1L;
    public NormalSeat(int row, int col) { super(row, col); }
    @Override public double priceFor(double basePrice) { return basePrice; }
    @Override public String getTypeName() { return "Normal"; }
    @Override public char getSymbol() { return ' '; }
}
