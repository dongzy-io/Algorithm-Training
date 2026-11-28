package cinema;

/** Hall category; each category has its own price coefficient. */
public enum HallType {
    STANDARD("Standard", 1.0),
    IMAX("IMAX", 1.3);

    private final String label;
    private final double rate;
    HallType(String label, double rate) { this.label = label; this.rate = rate; }
    public String getLabel() { return label; }
    public double getRate() { return rate; }
}
