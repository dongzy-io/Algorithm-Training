package cinema;

/** VIP seat in the prime area of a hall: 1.5 times the base price. */
public class VipSeat extends Seat {
    private static final long serialVersionUID=1L;
    public static final double RATE=1.5;
    public VipSeat(int row, int col){ super(row, col); }
    @Override public double priceFor(double basePrice){ return basePrice * RATE; }
    @Override public String getTypeName(){ return "VIP"; }
    @Override public char getSymbol(){ return 'V'; }
}
