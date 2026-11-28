package cinema;
import java.io.Serializable;

/** A sold ticket (order line). */
public class Ticket implements Serializable {
    private static final long serialVersionUID=1L;
    private final int id;
    private final int screeningId;
    private final int row, col;
    private final String buyer;
    private final TicketType type;
    private final double price;
    private boolean refunded;
    public Ticket(int id, int screeningId, int row, int col, String buyer, TicketType type, double price) {
        this.id=id; 
        this.screeningId=screeningId; 
        this.row=row; 
        this.col=col;
        this.buyer=buyer; 
        this.type=type; 
        this.price=price;
    }
    public int getId() { return id; }
    public int getScreeningId() { return screeningId; }
    public int getRow() { return row; }
    public int getCol() { return col; }
    public String getBuyer() { return buyer; }
    public TicketType getType() { return type; }
    public double getPrice() { return price; }
    public boolean isRefunded() { return refunded; }
    public void setRefunded(boolean refunded) { this.refunded = refunded; }
}
