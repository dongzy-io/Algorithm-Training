package cinema;
import java.io.Serializable;

/**
 * The city: a 2D grid. A cell is OPEN (walkable), BLOCKED (river, wall, building)
 * or holds the id (&gt; 0) of the cinema built on it. Cinema cells are walkable.
 */
public class City implements Serializable {
    private static final long serialVersionUID=1L;
    public static final int OPEN=0;
    public static final int BLOCKED=-1;
    private final int rows, cols;
    private final int[][] grid;
    public City(int rows, int cols){
        this.rows=rows; 
        this.cols=cols;
        this.grid=new int[rows][cols];
    }
    public int getRows() { return rows; }
    public int getCols() { return cols; }
    public int[][] getGrid() { return grid; }
    public boolean inside(int r, int c){ 
        return r>=0&&r<rows&&c>=0&&c<cols; 
    }
    public boolean isWalkable(int r, int c){ 
        return inside(r, c)&&grid[r][c]!=BLOCKED; 
    }
    /** Returns the id of the cinema at (r, c), or 0 if there is none. */
    public int cinemaIdAt(int r, int c){ 
        return inside(r, c)&&grid[r][c]>0?grid[r][c] : 0; 
    }
    public void block(int r, int c) { 
        if(inside(r, c)&&grid[r][c]==OPEN) 
            grid[r][c] = BLOCKED; 
    }
    public void placeCinema(int cinemaId, int r, int c) throws InvalidInputException {
        if(!inside(r, c)) 
            throw new InvalidInputException("Location (" + r + "," + c + ") is outside the city");
        if(grid[r][c]!=OPEN) 
            throw new InvalidInputException("Location (" + r + "," + c + ") is not free");
        grid[r][c]=cinemaId;
    }
}
