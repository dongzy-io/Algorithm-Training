package cinema;

/** Ticket category with its discount rate. */
public enum TicketType {
    ADULT("Adult", 1.0),
    STUDENT("Student", 0.6);

    private final String label;
    private final double rate;
    TicketType(String label, double rate) { 
        this.label=label; this.rate=rate; 
    }
    public String getLabel() { return label; }
    public double getRate() { return rate; }
}
