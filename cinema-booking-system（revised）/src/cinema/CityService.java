package cinema;

import java.util.*;

/** Location based queries on the city grid. */
public class CityService {
    private final CinemaSystem sys;
    private final ScheduleService schedule;
    public CityService(CinemaSystem sys, ScheduleService schedule) { this.sys = sys; this.schedule = schedule; }

    /** A cinema reached by BFS: walking distance, straight grid (Manhattan) distance and the path. */
    public record Found(Cinema cinema, int walkDist, int manhattan, List<int[]> path) {}
    /** A nearest cinema that shows a movie, with its earliest upcoming screening of that movie. */
    public record NearestShowing(Found found, Screening earliest) {}

    private void checkStart(int r, int c) throws InvalidInputException {
        City city = sys.getCity();
        if (!city.inside(r, c)) throw new InvalidInputException("Position (" + r + "," + c + ") is outside the city ("
                + city.getRows() + " rows x " + city.getCols() + " columns)");
        if (!city.isWalkable(r, c)) throw new InvalidInputException("Position (" + r + "," + c + ") is blocked");
    }

    private Found toFound(Algorithms.GridHit h) throws NotFoundException {
        Cinema c = sys.getCinema(sys.getCity().cinemaIdAt(h.row, h.col));
        return new Found(c, h.dist, 0, h.path);
    }
    private Found withManhattan(Found f, int r, int c) {
        return new Found(f.cinema(), f.walkDist(), Math.abs(f.cinema().getRow() - r) + Math.abs(f.cinema().getCol() - c), f.path());
    }

    /** The k nearest cinemas by walking distance around obstacles. */
    public List<Found> nearestCinemas(int r, int c, int k) throws CinemaException {
        checkStart(r, c);
        City city = sys.getCity();
        List<Algorithms.GridHit> hits = Algorithms.bfsNearest(city.getGrid(), City.BLOCKED, r, c,
                (x, y) -> city.cinemaIdAt(x, y) > 0, k);
        List<Found> res = new ArrayList<>();
        for (Algorithms.GridHit h : hits) res.add(withManhattan(toFound(h), r, c));
        return res;
    }

    /**
     * Nearest cinema that has at least one upcoming screening (start after the current time) of a
     * movie whose name contains the keyword. Combines the movie index with the grid BFS.
     */
    public NearestShowing nearestShowing(int r, int c, String keyword) throws CinemaException {
        checkStart(r, c);
        List<Movie> movies = schedule.findMovies(keyword);
        if (movies.isEmpty()) throw new NotFoundException("No movie matches \"" + keyword + "\"");
        Set<Integer> cinemaIds = new HashSet<>();
        for (Movie m : movies)
            for (Screening s : schedule.upcomingOfMovie(m, sys.getNow())) cinemaIds.add(s.getHall().getCinemaId());
        if (cinemaIds.isEmpty()) throw new NotFoundException("No upcoming screening of \"" + keyword + "\"");
        City city = sys.getCity();
        List<Algorithms.GridHit> hits = Algorithms.bfsNearest(city.getGrid(), City.BLOCKED, r, c,
                (x, y) -> cinemaIds.contains(city.cinemaIdAt(x, y)), 1);
        if (hits.isEmpty()) throw new NotFoundException("No reachable cinema shows \"" + keyword + "\"");
        Found f = withManhattan(toFound(hits.get(0)), r, c);
        Screening earliest = null;
        for (Movie m : movies)
            for (Screening s : schedule.upcomingOfMovie(m, sys.getNow()))
                if (s.getHall().getCinemaId() == f.cinema().getId()) {
                    if (earliest == null || s.getStart().isBefore(earliest.getStart())) earliest = s;
                    break;                       // list is sorted: first match is the earliest of this movie
                }
        return new NearestShowing(f, earliest);
    }
}
