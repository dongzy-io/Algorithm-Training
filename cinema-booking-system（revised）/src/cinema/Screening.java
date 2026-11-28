package cinema;
import java.io.Serializable;
import java.time.LocalDateTime;
import java.util.BitSet;

/** One showing of a movie in a hall. Sold seats are kept in a BitSet (index = row * cols + col). */
public class Screening implements Serializable{
    private static final long serialVersionUID=1L;
    private final int id;
    private final Movie movie;
    private final Hall hall;
    private final LocalDateTime start;
    private final BitSet sold;
    public Screening(int id, Movie movie, Hall hall, LocalDateTime start) {
        this.id=id; 
        this.movie=movie; 
        this.hall=hall; 
        this.start=start;
        this.sold=new BitSet(hall.capacity());
    }
    public int getId() { return id; }
    public Movie getMovie() { return movie; }
    public Hall getHall() { return hall; }
    public LocalDateTime getStart() { return start; }
    public LocalDateTime end() { return start.plusMinutes(movie.getDurationMin()); }

    private int idx(int r, int c) { return r*hall.getCols()+c; }
    public boolean isSold(int r, int c) { return sold.get(idx(r, c)); }
    public void occupy(int r, int c) { sold.set(idx(r, c)); }
    public void release(int r, int c) { sold.clear(idx(r, c)); }
    public int soldCount() { return sold.cardinality(); }
    public int freeCount() { return hall.capacity()-soldCount(); }
    public double occupancyRate() { return 100.0*soldCount()/hall.capacity(); }
}
