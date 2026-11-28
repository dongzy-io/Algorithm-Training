package cinema;

import java.io.*;
import java.time.LocalDateTime;
import java.util.*;

/**
 * Data container of the whole system plus persistence. It holds the city, cinemas, halls, movies,
 * screenings, tickets, the revenue ledger and the simulated clock. Business logic lives in the
 * service classes (ScheduleService, BookingService, StatsService, CityService).
 */
public class CinemaSystem implements Serializable {
    private static final long serialVersionUID = 2L;

    private LocalDateTime now;                                                 // simulated current time
    private final City city;
    private final List<Movie> movies=new ArrayList<>();
    private final List<Cinema> cinemas=new ArrayList<>();
    private final List<Hall> halls=new ArrayList<>();
    private final List<Screening> screenings = new ArrayList<>();               // sorted by start time
    private final Map<Integer, List<Screening>> hallSchedule = new HashMap<>();  // hall id -> sorted list
    private final Map<Integer, List<Screening>> movieIndex = new HashMap<>();    // movie id -> sorted list
    private final Map<Integer, Screening> screeningById = new HashMap<>();
    private final Map<Integer, Ticket> tickets = new LinkedHashMap<>();
    private final Ledger ledger = new Ledger();
    private int nextMovieId = 1, nextScreeningId = 1, nextTicketId = 1001;

    public CinemaSystem(City city, LocalDateTime now) { this.city = city; this.now = now; }

    // ----- clock -----
    public LocalDateTime getNow() { return now; }
    public void setNow(LocalDateTime now) { this.now = now; }

    // ----- plain getters -----
    public City getCity() { return city; }
    public List<Movie> getMovies() { return movies; }
    public List<Cinema> getCinemas() { return cinemas; }
    public List<Hall> getHalls() { return halls; }
    public List<Screening> getScreenings() { return screenings; }
    public Collection<Ticket> getTickets() { return tickets.values(); }
    public Ledger getLedger() { return ledger; }

    // ----- lookups by id -----
    public Movie getMovie(int id) throws NotFoundException {
        for (Movie m : movies) if (m.getId() == id) return m;
        throw new NotFoundException("Movie " + id + " not found");
    }
    public Cinema getCinema(int id) throws NotFoundException {
        for (Cinema c : cinemas) if (c.getId() == id) return c;
        throw new NotFoundException("Cinema " + id + " not found");
    }
    public Hall getHall(int id) throws NotFoundException {
        for (Hall h : halls) if (h.getId() == id) return h;
        throw new NotFoundException("Hall " + id + " not found");
    }
    public Screening getScreening(int id) throws NotFoundException {
        Screening s = screeningById.get(id);
        if (s == null) throw new NotFoundException("Screening " + id + " not found");
        return s;
    }
    public Ticket getTicket(int id) throws NotFoundException {
        Ticket t = tickets.get(id);
        if (t == null) throw new NotFoundException("Ticket " + id + " not found");
        return t;
    }
    public Cinema cinemaOf(Hall h) throws NotFoundException { return getCinema(h.getCinemaId()); }

    /** Sorted screening list of one hall (never null). */
    public List<Screening> scheduleOf(Hall h) {
        return hallSchedule.computeIfAbsent(h.getId(), k -> new ArrayList<>());
    }
    /** Sorted screening list of one movie (never null). */
    public List<Screening> screeningsOfMovie(Movie m) {
        return movieIndex.computeIfAbsent(m.getId(), k -> new ArrayList<>());
    }

    // ----- mutators used by the services -----
    public int newMovieId() { return nextMovieId++; }
    public int newScreeningId() { return nextScreeningId++; }
    public int newTicketId() { return nextTicketId++; }
    public void addMovie(Movie m) { movies.add(m); }
    public void addCinema(Cinema c) { cinemas.add(c); }
    public void addHall(Hall h) throws NotFoundException { 
        halls.add(h); 
        getCinema(h.getCinemaId()).getHalls().add(h); 
    }
    public void putTicket(Ticket t) { tickets.put(t.getId(), t); }

    /** Inserts a screening into all sorted structures at the position found by binary search. */
    public void insertScreening(Screening s) {
        List<Screening> hs = scheduleOf(s.getHall());
        hs.add(Algorithms.lowerBound(hs, s.getStart()), s);
        screenings.add(Algorithms.lowerBound(screenings, s.getStart()), s);
        List<Screening> ms = screeningsOfMovie(s.getMovie());
        ms.add(Algorithms.lowerBound(ms, s.getStart()), s);
        screeningById.put(s.getId(), s);
    }

    // ----- persistence (object serialization) -----
    public boolean save(String path) {
        try (ObjectOutputStream out = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream(path)))) {
            out.writeObject(this);
            return true;
        } catch (IOException e) {
            System.out.println("[WARN] Could not save data: " + e.getMessage());
            return false;
        }
    }

    /** Loads a saved system; returns null if the file does not exist or cannot be read. */
    public static CinemaSystem load(String path) {
        File f = new File(path);
        if (!f.exists()) return null;
        try (ObjectInputStream in = new ObjectInputStream(new BufferedInputStream(new FileInputStream(f)))) {
            return (CinemaSystem) in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("[WARN] Could not read data file (" + e.getMessage() + "); sample data will be used.");
            return null;
        }
    }
}
