package cinema;
import java.io.Serializable;

/** A movie that can be scheduled. */
public class Movie implements Serializable{
    private static final long serialVersionUID = 1L;
    private final int id;
    private final String name;
    private final int durationMin;
    private final double basePrice;
    public Movie(int id, String name, int durationMin, double basePrice) {
        this.id=id; 
        this.name=name; 
        this.durationMin=durationMin; 
        this.basePrice=basePrice;
    }
    public int getId(){ return id; }
    public String getName(){ return name; }
    public int getDurationMin(){ return durationMin; }
    public double getBasePrice(){ return basePrice; }
    @Override public String toString(){ return "\"" + name + "\""; }
}
