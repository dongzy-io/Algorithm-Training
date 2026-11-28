package cinema;

import java.io.Serializable;

/** Abstract seat. Concrete subclasses define their own pricing (polymorphism). */
public abstract class Seat implements Priced, Serializable {
    private static final long serialVersionUID = 1L;
    protected final int row;   // 0-based
    protected final int col;   // 0-based

    protected Seat(int row, int col) { this.row = row; this.col = col; }

    public int getRow() { return row; }
    public int getCol() { return col; }

    /** Human readable seat type. */
    public abstract String getTypeName();
    /** Symbol shown for a free seat on the seat map. */
    public abstract char getSymbol();
}
