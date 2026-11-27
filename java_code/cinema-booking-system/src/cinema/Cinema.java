package cinema;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

/** A cinema located at a cell of the city grid; it owns several halls. */
public class Cinema implements Serializable {
    private static final long serialVersionUID = 1L;
    private final int id;
    private final String name;
    private final int row, col;          // location on the city grid
    private final List<Hall> halls=new ArrayList<>();
    public Cinema(int id, String name, int row, int col) {
        this.id = id; 
        this.name = name; 
        this.row = row; 
        this.col = col;
    }
    public int getId() { return id; }
    public String getName() { return name; }
    public int getRow() { return row; }
    public int getCol() { return col; }
    public List<Hall> getHalls() { return halls; }
    @Override 
    public String toString(){ 
        
        return name; 
    }
}
