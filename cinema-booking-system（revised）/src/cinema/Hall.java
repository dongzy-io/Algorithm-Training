package cinema;

import java.io.Serializable;

/** A screening hall. Its seat layout is stored in a 2D array seats[row][col]. */
public class Hall implements Serializable {
    private static final long serialVersionUID=1L;
    private final int id;
    private final int cinemaId;
    private final String name;
    private final HallType type;
    private final int rows, cols;
    private final Seat[][] seats;
    public Hall(int id, int cinemaId, String name, HallType type, int rows, int cols, int vipRowFrom, int vipRowTo) {
        this.id=id; 
        this.cinemaId=cinemaId; 
        this.name=name; 
        this.type=type;
        this.rows=rows; 
        this.cols=cols;
        this.seats=new Seat[rows][cols];
        for (int r=0; r<rows; r++) {
            for (int c=0; c<cols; c++) {
                boolean vip=r>=vipRowFrom&&r<=vipRowTo&&c>=2&&c<cols-2;
                seats[r][c]=vip? new VipSeat(r, c) : new NormalSeat(r, c);
            }
        }
    }
    public int getId() { return id; }
    public int getCinemaId() { return cinemaId; }
    public String getName() { return name; }
    public HallType getType() { return type; }
    public int getRows() { return rows; }
    public int getCols() { return cols; }
    public int capacity() { return rows * cols; }
    public Seat getSeat(int r, int c) { return seats[r][c]; }
    @Override
    public String toString(){
    return "Hall{" +
            "id=" + id +
            ", cinemaId=" + cinemaId +
            ", name='" + name + '\'' +
            ", type=" + type +
            ", rows=" + rows +
            ", cols=" + cols +
            ", capacity=" + capacity() +
            '}';
    }
}
