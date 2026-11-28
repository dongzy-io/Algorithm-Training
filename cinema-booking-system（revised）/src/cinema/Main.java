package cinema;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.*;

/** Console user interface of the cinema booking system. */
public class Main {
    static final String DATA_FILE = "cinema.dat";
    static final DateTimeFormatter DT = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
    static final Scanner in = new Scanner(System.in);

    static CinemaSystem sys;
    static ScheduleService schedule;
    static BookingService booking;
    static StatsService stats;
    static CityService cityService;

    public static void main(String[] args) {
        sys = CinemaSystem.load(DATA_FILE);
        if (sys == null) {
            sys = SampleData.build();
            sys.save(DATA_FILE);
            System.out.println("First start: sample data loaded.");
        } else {
            System.out.println("Data loaded from " + DATA_FILE + ".");
        }
        schedule = new ScheduleService(sys);
        booking = new BookingService(sys);
        stats = new StatsService(sys, booking);
        cityService = new CityService(sys, schedule);
        try {
            mainMenu();
        } catch (NoSuchElementException e) {          // input stream closed
            System.out.println("\nEnd of input.");
        } finally {
            sys.save(DATA_FILE);
        }
    }

    // ------------------------------------------------------------------ menus
    static void mainMenu() {
        while (true) {
            System.out.println("\n=============== CINEMA BOOKING SYSTEM ===============");
            System.out.println("Current time: " + Fmt.dt(sys.getNow()) + "  (" + sys.getNow().toLocalDate() + ")");
            System.out.println("1 City & cinemas     2 Schedule & search   3 Booking");
            System.out.println("Current week: " + weekText());
            System.out.println("4 Statistics         5 Administration      6 Clock");
            System.out.println("7 Weekly queries (cinema / time slot / movie)");
            System.out.println("0 Save and exit");
            String c = ask("Choose");
            try {
                switch (c) {
                    case "1": cityMenu(); break;
                    case "2": scheduleMenu(); break;
                    case "3": bookingMenu(); break;
                    case "4": statsMenu(); break;
                    case "5": adminMenu(); break;
                    case "6": clockMenu(); break;
                    case "7": queryMenu(); break;
                    case "0": sys.save(DATA_FILE); System.out.println("Data saved. Bye!"); return;
                    default: throw new InvalidInputException("Unknown menu item: " + c);
                }
            } catch (CinemaException e) {
                System.out.println("[ERROR] " + e.getMessage());
            }
        }
    }

    interface Action { void run() throws CinemaException; }

    /** Generic submenu loop: items are "label" strings, actions in the same order, "0" goes back. */
    static void submenu(String title, String[] labels, Action[] actions) {
        while (true) {
            System.out.println("\n--- " + title + " ---");
            for (int i = 0; i < labels.length; i++) System.out.println((i + 1) + " " + labels[i]);
            System.out.println("0 Back");
            String c = ask("Choose");
            if (c.equals("0")) return;
            try {
                int k = Integer.parseInt(c);
                if (k < 1 || k > actions.length) throw new NumberFormatException();
                actions[k - 1].run();
            } catch (NumberFormatException e) {
                System.out.println("[ERROR] Unknown menu item: " + c);
            } catch (CinemaException e) {
                System.out.println("[ERROR] " + e.getMessage());
            }
        }
    }

    static void cityMenu() {
        submenu("City & cinemas",
                new String[]{"Show city map", "List cinemas and halls", "Find nearest cinemas", "Find nearest cinema showing a movie"},
                new Action[]{Main::showCityMap, Main::listCinemas, Main::nearestCinemas, Main::nearestShowing});
    }
    static void scheduleMenu() {
        submenu("Schedule & search",
                new String[]{"Movies", "Weekly timetable of a hall", "Search a movie by name", "What is playing at a given time", "Screenings on a date"},
                new Action[]{Main::listMovies, Main::weeklyTimetable, Main::searchMovie, Main::statusAtTime, Main::screeningsOnDate});
    }
    static void bookingMenu() {
        submenu("Booking",
                new String[]{"Show seat map", "Book seats (choose seats)", "Book consecutive seats (recommendation)", "Refund a ticket", "Find tickets"},
                new Action[]{Main::showSeatMap, Main::bookManual, Main::bookRecommended, Main::refund, Main::findTickets});
    }
    static void queryMenu() {
        submenu("Weekly queries (give any two of cinema / time slot / movie, get the third)",
                new String[]{"Cinema + time slot -> movies, halls and seats", "Cinema + movie -> showtimes, halls and occupancy",
                        "Movie + time slot -> cinemas, locations and halls", "Tickets bought for the current week", "Show current week"},
                new Action[]{Main::queryCinemaTime, Main::queryCinemaMovie, Main::queryMovieTime, Main::weekTickets,
                        () -> System.out.println("Current week: " + weekText() + "   (now " + Fmt.dt(sys.getNow()) + ")")});
    }
    static void statsMenu() {
        submenu("Statistics",
                new String[]{"Screenings: prices, sales, revenue", "Revenue of halls and cinemas", "Movie box office and top movies", "Cinema occupancy ranking"},
                new Action[]{Main::statScreenings, Main::statHallsCinemas, Main::statMovies, Main::statOccupancy});
    }
    static void adminMenu() {
        submenu("Administration",
                new String[]{"Add a movie", "Add a screening (conflict check)", "Find earliest free slot for a movie"},
                new Action[]{Main::addMovie, Main::addScreening, Main::findSlot});
    }
    static void clockMenu() {
        submenu("Clock",
                new String[]{"Show current time", "Set current time", "Advance time by N minutes"},
                new Action[]{() -> System.out.println("Current time: " + sys.getNow().format(DT)),
                        () -> { sys.setNow(askDateTime("New time (yyyy-MM-dd HH:mm)")); sys.save(DATA_FILE);
                            System.out.println("Time set to " + Fmt.dt(sys.getNow())); },
                        () -> { sys.setNow(sys.getNow().plusMinutes(askInt("Minutes"))); sys.save(DATA_FILE);
                            System.out.println("Time is now " + Fmt.dt(sys.getNow())); }});
    }

    // ------------------------------------------------------------------ input helpers
    static String ask(String prompt) {
        System.out.print(prompt + "> ");
        String s = in.nextLine().trim();
        System.out.println(s);      // echo the answer so that logs of scripted runs are readable
        return s;
    }
    static int askInt(String prompt) throws InvalidInputException {
        String s = ask(prompt);
        try { return Integer.parseInt(s); }
        catch (NumberFormatException e) { throw new InvalidInputException("\"" + s + "\" is not a valid integer"); }
    }
    static double askDouble(String prompt) throws InvalidInputException {
        String s = ask(prompt);
        try { return Double.parseDouble(s); }
        catch (NumberFormatException e) { throw new InvalidInputException("\"" + s + "\" is not a valid number"); }
    }
    static LocalDateTime askDateTime(String prompt) throws InvalidInputException {
        String s = ask(prompt);
        try { return LocalDateTime.parse(s, DT); }
        catch (DateTimeParseException e) { throw new InvalidInputException("Time format must be yyyy-MM-dd HH:mm, e.g. 2026-11-28 09:30"); }
    }
    static LocalDate parseDate(String s) throws InvalidInputException {
        try { return LocalDate.parse(s); }
        catch (DateTimeParseException e) { throw new InvalidInputException("Date format must be yyyy-MM-dd, e.g. 2026-11-28"); }
    }
    static int[] askPosition() throws InvalidInputException {
        String s = ask("Your position (row column, e.g. 8 8)");
        String[] p = s.split("\\s+");
        if (p.length != 2) throw new InvalidInputException("Enter two integers: row and column");
        try { return new int[]{Integer.parseInt(p[0]), Integer.parseInt(p[1])}; }
        catch (NumberFormatException e) { throw new InvalidInputException("Enter two integers: row and column"); }
    }
    static TicketType askTicketType() throws InvalidInputException {
        String s = ask("Ticket type (1 Adult, 2 Student)");
        if (s.equals("1")) return TicketType.ADULT;
        if (s.equals("2")) return TicketType.STUDENT;
        throw new InvalidInputException("Ticket type must be 1 or 2");
    }
    static Hall askHall() throws CinemaException {
        listCinemas();
        return sys.getHall(askInt("Hall id"));
    }

    // ------------------------------------------------------------------ city
    /** Prints the grid: # blocked, . open, digit = cinema id, @ = user, * = path. */
    static void printCityMap(Integer ur, Integer uc, List<int[]> path) {
        City city = sys.getCity();
        Set<Integer> onPath = new HashSet<>();
        if (path != null) for (int[] p : path) onPath.add(p[0] * city.getCols() + p[1]);
        StringBuilder h1 = new StringBuilder("     "), h2 = new StringBuilder("     ");
        for (int c = 0; c < city.getCols(); c++) {
            h1.append(c >= 10 ? String.valueOf(c / 10) : " ").append(' ');
            h2.append(c % 10).append(' ');
        }
        System.out.println(h1); System.out.println(h2);
        for (int r = 0; r < city.getRows(); r++) {
            StringBuilder sb = new StringBuilder(String.format("%3d  ", r));
            for (int c = 0; c < city.getCols(); c++) {
                char ch;
                if (ur != null && r == ur && c == uc) ch = '@';
                else if (city.cinemaIdAt(r, c) > 0) ch = (char) ('0' + city.cinemaIdAt(r, c));
                else if (onPath.contains(r * city.getCols() + c)) ch = '*';
                else if (!city.isWalkable(r, c)) ch = '#';
                else ch = '.';
                sb.append(ch).append(' ');
            }
            System.out.println(sb);
        }
        System.out.println("Legend: # blocked (river / buildings)   . open   1-9 cinema id   @ you   * path");
    }
    static void showCityMap() { printCityMap(null, null, null); }

    static void listCinemas() {
        for (Cinema c : sys.getCinemas()) {
            System.out.println("Cinema " + c.getId() + ": " + c.getName() + " at (row " + c.getRow() + ", col " + c.getCol() + ")");
            for (Hall h : c.getHalls())
                System.out.println("    Hall id " + h.getId() + ": " + h.getName() + " [" + h.getType().getLabel() + "], "
                        + h.getRows() + " rows x " + h.getCols() + " seats");
        }
    }

    static void nearestCinemas() throws CinemaException {
        int[] p = askPosition();
        List<CityService.Found> list = cityService.nearestCinemas(p[0], p[1], 3);
        System.out.println("Nearest cinemas by walking distance (steps around obstacles):");
        int i = 1;
        for (CityService.Found f : list)
            System.out.printf("%d. %s | walking %d steps | straight-line grid distance %d%n", i++, f.cinema().getName(), f.walkDist(), f.manhattan());
        if (!list.isEmpty()) {
            System.out.println("Path to the nearest one:");
            printCityMap(p[0], p[1], list.get(0).path());
        }
    }

    static void nearestShowing() throws CinemaException {
        int[] p = askPosition();
        String kw = ask("Movie name (or part of it)");
        CityService.NearestShowing r = cityService.nearestShowing(p[0], p[1], kw);
        System.out.printf("Nearest cinema showing it: %s (walking %d steps)%n", r.found().cinema().getName(), r.found().walkDist());
        if (r.earliest() != null) {
            Screening s = r.earliest();
            System.out.printf("Earliest upcoming screening there: #%d %s, %s, %s, %s%n", s.getId(), s.getMovie(),
                    s.getHall().getName(), Fmt.dt(s.getStart()), priceText(s));
        }
        printCityMap(p[0], p[1], r.found().path());
    }

    // ------------------------------------------------------------------ schedule
    static String priceText(Screening s) {
        double[] pr = booking.adultPrices(s);
        return "price " + Fmt.money(pr[0]) + " / VIP " + Fmt.money(pr[1]);
    }

    static void listMovies() {
        System.out.println("Id | Name | Duration | Base price");
        for (Movie m : sys.getMovies())
            System.out.printf("%d | %s | %d min | %s%n", m.getId(), m.getName(), m.getDurationMin(), Fmt.money(m.getBasePrice()));
    }

    static void weeklyTimetable() throws CinemaException {
        Hall h = askHall();
        String d = ask("First day of the week (yyyy-MM-dd, blank = today)");
        LocalDate from = d.isEmpty() ? sys.getNow().toLocalDate() : parseDate(d);
        System.out.println("Timetable of " + sys.cinemaOf(h).getName() + " / " + h.getName() + " [" + h.getType().getLabel() + "]");
        for (Map.Entry<LocalDate, List<Screening>> e : schedule.weeklyTimetable(h, from).entrySet()) {
            StringBuilder sb = new StringBuilder(Fmt.dt(e.getKey().atStartOfDay()).substring(0, 9) + ": ");
            if (e.getValue().isEmpty()) sb.append("(no screenings)");
            for (Screening s : e.getValue())
                sb.append(Fmt.time(s.getStart())).append('-').append(Fmt.time(s.end())).append(' ').append(s.getMovie()).append("  ");
            System.out.println(sb.toString().trim());
        }
    }

    static void searchMovie() throws CinemaException {
        String kw = ask("Movie name (or part of it)");
        List<Movie> found = schedule.findMovies(kw);
        if (found.isEmpty()) throw new NotFoundException("No movie matches \"" + kw + "\"");
        for (Movie m : found) {
            List<Screening> list = schedule.upcomingOfMovie(m, sys.getNow());
            System.out.println("\n" + m + " (" + m.getDurationMin() + " min): " + list.size() + " upcoming screenings");
            int shown = 0;
            for (Screening s : list) {
                if (shown++ == 12) { System.out.println("  ... (" + (list.size() - 12) + " more)"); break; }
                System.out.printf("  #%d | %s / %s | %s-%s | %s | free %d/%d%n", s.getId(), sys.cinemaOf(s.getHall()).getName(),
                        s.getHall().getName(), Fmt.dt(s.getStart()), Fmt.time(s.end()), priceText(s),
                        s.freeCount(), s.getHall().capacity());
            }
        }
    }

    static void statusAtTime() throws CinemaException {
        LocalDateTime t = askDateTime("Time (yyyy-MM-dd HH:mm)");
        System.out.println("Status of every hall at " + Fmt.dt(t) + ":");
        for (ScheduleService.HallStatus st : schedule.statusAt(t)) {
            String detail;
            switch (st.state()) {
                case "PLAYING": detail = st.current().getMovie() + " until " + Fmt.time(st.current().end())
                        + " (#" + st.current().getId() + ", free " + st.current().freeCount() + ")"; break;
                case "CLEANING": detail = "cleaning after " + st.current().getMovie(); break;
                default: detail = "idle";
            }
            if (!st.state().equals("PLAYING") && st.next() != null)
                detail += "; next: " + st.next().getMovie() + " at " + Fmt.dt(st.next().getStart());
            System.out.printf("%s / %s | %s | %s%n", st.cinema().getName(), st.hall().getName(), st.state(), detail);
        }
    }

    static void screeningsOnDate() throws CinemaException {
        LocalDate d = parseDate(ask("Date (yyyy-MM-dd)"));
        List<Screening> list = schedule.onDate(d);
        if (list.isEmpty()) { System.out.println("(no screenings)"); return; }
        for (Screening s : list)
            System.out.printf("#%d | %s-%s | %s | %s / %s | free %d/%d%n", s.getId(), Fmt.time(s.getStart()), Fmt.time(s.end()),
                    s.getMovie(), sys.cinemaOf(s.getHall()).getName(), s.getHall().getName(), s.freeCount(), s.getHall().capacity());
    }


    // ------------------------------------------------------------------ weekly queries
    static String weekText() {
        LocalDate s = schedule.weekStart();
        return Fmt.day(s) + " ~ " + Fmt.day(s.plusDays(6)) + "  (" + s + " to " + s.plusDays(6) + ")";
    }

    /** Parses blank (null), a date (yyyy-MM-dd) or a date-time (yyyy-MM-dd HH:mm). A date as end means the end of that day. */
    static LocalDateTime parseFlexible(String s, boolean endOfDay) throws InvalidInputException {
        if (s.isEmpty()) return null;
        try {
            if (s.length() <= 10) {
                LocalDate d = LocalDate.parse(s);
                return endOfDay ? d.plusDays(1).atStartOfDay() : d.atStartOfDay();
            }
            return LocalDateTime.parse(s, DT);
        } catch (DateTimeParseException e) {
            throw new InvalidInputException("Use yyyy-MM-dd or yyyy-MM-dd HH:mm, e.g. 2026-11-29 or 2026-11-29 18:00");
        }
    }
    /** Time slot as {from, to}; screenings starting in [from, to) are selected. Blank = the current week. */
    static LocalDateTime[] askRange() throws InvalidInputException {
        LocalDateTime from = parseFlexible(ask("Time slot from (date or date time, blank = start of current week)"), false);
        LocalDateTime to = parseFlexible(ask("Time slot to (date = end of that day, blank = 7 days after 'from' / end of current week)"), true);
        if (from == null) from = schedule.weekFrom();
        if (to == null) to = (from.equals(schedule.weekFrom())) ? schedule.weekTo() : from.plusDays(7);
        if (!from.isBefore(to)) throw new InvalidInputException("The start of the time slot must be before its end");
        return new LocalDateTime[]{from, to};
    }
    static String rangeText(LocalDateTime[] r) { return Fmt.dt(r[0]) + " -> " + Fmt.dt(r[1]) + " (end excluded)"; }

    static Cinema askCinema() throws CinemaException {
        listCinemas();
        return sys.getCinema(askInt("Cinema id"));
    }
    /** Accepts a movie id or (part of) a movie name that matches exactly one movie. */
    static Movie askMovie() throws CinemaException {
        listMovies();
        String s = ask("Movie id or name");
        try { return sys.getMovie(Integer.parseInt(s)); } catch (NumberFormatException ignored) { /* not an id: search by name */ }
        List<Movie> found = schedule.findMovies(s);
        if (found.isEmpty()) throw new NotFoundException("No movie matches \"" + s + "\"");
        if (found.size() > 1) throw new InvalidInputException("Several movies match \"" + s + "\"; please use the movie id");
        return found.get(0);
    }

    static String hallText(Hall h) { return h.getName() + " [" + h.getType().getLabel() + "]"; }
    static String locText(Cinema c) { return "grid (row " + c.getRow() + ", col " + c.getCol() + ")"; }

    static void printSummary(List<Screening> list) {
        int sold = 0, cap = 0;
        for (Screening s : list) { sold += s.soldCount(); cap += s.getHall().capacity(); }
        System.out.printf("Total: %d screenings, sold %d/%d seats, average occupancy %.1f%%%n", list.size(), sold, cap, cap == 0 ? 0 : 100.0 * sold / cap);
    }

    /** Query 1: cinema + time slot -> every movie, hall and seat state in that slot. */
    static void queryCinemaTime() throws CinemaException {
        Cinema c = askCinema();
        LocalDateTime[] r = askRange();
        List<Screening> list = schedule.inCinema(c, r[0], r[1]);
        System.out.println(c.getName() + " at " + locText(c) + " | screenings starting " + rangeText(r));
        if (list.isEmpty()) { System.out.println("(no screenings)"); return; }
        System.out.println("Id | Time | Movie | Hall | Adult price | VIP price | Sold/Cap | Occupancy");
        Map<String, Integer> movies = new LinkedHashMap<>();
        for (Screening s : list) {
            double[] pr = booking.adultPrices(s);
            System.out.printf("#%d | %s-%s | %s | %s | %s | %s | %d/%d | %.1f%%%n", s.getId(), Fmt.dt(s.getStart()), Fmt.time(s.end()),
                    s.getMovie(), hallText(s.getHall()), Fmt.money(pr[0]), Fmt.money(pr[1]), s.soldCount(), s.getHall().capacity(), s.occupancyRate());
            movies.merge(s.getMovie().toString(), 1, Integer::sum);
        }
        StringBuilder sb = new StringBuilder("Movies playing: ");
        for (Map.Entry<String, Integer> e : movies.entrySet()) sb.append(e.getKey()).append(" x").append(e.getValue()).append("  ");
        System.out.println(sb.toString().trim());
        printSummary(list);
    }

    /** Query 2: cinema + movie -> all showtimes of the movie in this cinema with hall and occupancy. */
    static void queryCinemaMovie() throws CinemaException {
        Cinema c = askCinema();
        Movie m = askMovie();
        LocalDateTime[] r = askRange();
        List<Screening> list = schedule.ofMovieInCinema(c, m, r[0], r[1]);
        System.out.println(m + " (" + m.getDurationMin() + " min) in " + c.getName() + " at " + locText(c) + " | screenings starting " + rangeText(r));
        if (list.isEmpty()) { System.out.println("(no screenings)"); return; }
        System.out.println("Id | Time | Hall | Adult price | VIP price | Sold/Cap | Occupancy");
        Map<LocalDate, Integer> perDay = new TreeMap<>();
        for (Screening s : list) {
            double[] pr = booking.adultPrices(s);
            System.out.printf("#%d | %s-%s | %s | %s | %s | %d/%d | %.1f%%%n", s.getId(), Fmt.dt(s.getStart()), Fmt.time(s.end()),
                    hallText(s.getHall()), Fmt.money(pr[0]), Fmt.money(pr[1]), s.soldCount(), s.getHall().capacity(), s.occupancyRate());
            perDay.merge(s.getStart().toLocalDate(), 1, Integer::sum);
        }
        StringBuilder sb = new StringBuilder("Per day: ");
        for (Map.Entry<LocalDate, Integer> e : perDay.entrySet()) sb.append(Fmt.day(e.getKey())).append(' ').append(e.getValue()).append("  ");
        System.out.println(sb.toString().trim());
        printSummary(list);
    }

    /** Query 3: movie + time slot -> every cinema that shows it, with location, hall and seats. */
    static void queryMovieTime() throws CinemaException {
        Movie m = askMovie();
        LocalDateTime[] r = askRange();
        Map<Cinema, List<Screening>> groups = schedule.ofMovieByCinema(m, r[0], r[1]);
        System.out.println(m + " (" + m.getDurationMin() + " min) | screenings starting " + rangeText(r));
        if (groups.isEmpty()) { System.out.println("(no cinema shows it in this time slot)"); return; }
        List<Screening> all = new ArrayList<>();
        for (Map.Entry<Cinema, List<Screening>> e : groups.entrySet()) {
            Cinema c = e.getKey();
            System.out.println("\nCinema " + c.getId() + ": " + c.getName() + " at " + locText(c));
            System.out.println("  Id | Time | Hall | Adult price | VIP price | Sold/Cap | Occupancy");
            for (Screening s : e.getValue()) {
                double[] pr = booking.adultPrices(s);
                System.out.printf("  #%d | %s-%s | %s | %s | %s | %d/%d | %.1f%%%n", s.getId(), Fmt.dt(s.getStart()), Fmt.time(s.end()),
                        hallText(s.getHall()), Fmt.money(pr[0]), Fmt.money(pr[1]), s.soldCount(), s.getHall().capacity(), s.occupancyRate());
                all.add(s);
            }
        }
        System.out.println("\nCinemas showing it: " + groups.size() + " of " + sys.getCinemas().size());
        printSummary(all);
    }

    /** Tickets of one buyer (or all buyers) for screenings in the time slot (default: the current week). */
    static void weekTickets() throws CinemaException {
        String buyer = ask("Buyer name (blank = all buyers)");
        LocalDateTime[] r = askRange();
        List<Ticket> list = booking.ticketsInRange(buyer, r[0], r[1]);
        System.out.println("Tickets for screenings starting " + rangeText(r) + (buyer.isEmpty() ? "" : " | buyer " + buyer));
        if (list.isEmpty()) { System.out.println("(no tickets)"); return; }
        printTickets(list);
        int valid = 0, refunded = 0; double spent = 0;
        for (Ticket t : list) {
            if (t.isRefunded()) refunded++;
            else { valid++; spent += t.getPrice(); }
        }
        System.out.println("Valid tickets: " + valid + ", total " + Fmt.money(spent) + ", refunded tickets: " + refunded);
    }

    // ------------------------------------------------------------------ booking
    static void printSeatMap(Screening s, Set<Integer> highlight) throws NotFoundException {
        Hall h = s.getHall();
        System.out.println("------ " + s.getMovie() + " | " + sys.cinemaOf(h).getName() + " / " + h.getName() + " | " + Fmt.dt(s.getStart()) + " ------");
        System.out.println("            [ SCREEN ]");
        StringBuilder head = new StringBuilder("     ");
        for (int c = 0; c < h.getCols(); c++) head.append(String.format("%3d ", c + 1));
        System.out.println(head);
        for (int r = 0; r < h.getRows(); r++) {
            StringBuilder sb = new StringBuilder(String.format("R%-3d ", r + 1));
            for (int c = 0; c < h.getCols(); c++) {
                char ch;
                if (s.isSold(r, c)) ch = 'X';
                else if (highlight.contains(r * h.getCols() + c)) ch = '*';
                else ch = h.getSeat(r, c).getSymbol();
                sb.append('[').append(ch).append("] ");
            }
            System.out.println(sb);
        }
        System.out.println("Legend: [ ] normal  [V] VIP  [X] sold  [*] recommended      Free " + s.freeCount() + "/" + h.capacity());
        System.out.println("Adult " + priceText(s) + "; student 60%; before 12:00 20% off");
    }

    static void showSeatMap() throws CinemaException {
        printSeatMap(sys.getScreening(askInt("Screening id")), Collections.emptySet());
    }

    static void printTickets(List<Ticket> list) throws CinemaException {
        for (Ticket t : list) {
            Screening s = sys.getScreening(t.getScreeningId());
            System.out.printf("Ticket %d | %s | %s / %s | %s | row %d seat %d (%s) | %s %s | %s%s%n", t.getId(), s.getMovie(),
                    sys.cinemaOf(s.getHall()).getName(), s.getHall().getName(), Fmt.dt(s.getStart()), t.getRow() + 1, t.getCol() + 1,
                    s.getHall().getSeat(t.getRow(), t.getCol()).getTypeName(), t.getBuyer(), t.getType().getLabel(),
                    Fmt.money(t.getPrice()), t.isRefunded() ? " [REFUNDED]" : "");
        }
    }

    static void bookManual() throws CinemaException {
        Screening s = sys.getScreening(askInt("Screening id"));
        printSeatMap(s, Collections.emptySet());
        String line = ask("Seats as row-seat separated by spaces (e.g. 4-5 4-6)");
        List<int[]> seats = new ArrayList<>();
        for (String tok : line.split("\\s+")) {
            String[] p = tok.split("-");
            if (p.length != 2) throw new InvalidInputException("Bad seat format: " + tok);
            try { seats.add(new int[]{Integer.parseInt(p[0]) - 1, Integer.parseInt(p[1]) - 1}); }
            catch (NumberFormatException e) { throw new InvalidInputException("Bad seat format: " + tok); }
        }
        String buyer = ask("Buyer name");
        TicketType type = askTicketType();
        List<Ticket> res = booking.book(s.getId(), seats, buyer, type);
        sys.save(DATA_FILE);
        System.out.println("Booking successful, " + res.size() + " ticket(s):");
        printTickets(res);
    }

    static void bookRecommended() throws CinemaException {
        Screening s = sys.getScreening(askInt("Screening id"));
        int k = askInt("Number of people");
        List<Algorithms.SeatGroup> rec = booking.recommend(s, k, 3);
        if (rec.isEmpty()) { System.out.println("No block of " + k + " consecutive free seats is available."); return; }
        Set<Integer> hl = new HashSet<>();
        int cols = s.getHall().getCols();
        System.out.println("Recommended options (lower score is better):");
        for (int i = 0; i < rec.size(); i++) {
            Algorithms.SeatGroup g = rec.get(i);
            System.out.printf("Option %d: row %d, seats %d-%d, score %.2f%n", i + 1, g.row + 1, g.startCol + 1, g.startCol + g.size, g.score);
            if (i == 0) for (int c = 0; c < g.size; c++) hl.add(g.row * cols + g.startCol + c);
        }
        System.out.println("(option 1 is marked with [*] on the map)");
        printSeatMap(s, hl);
        int pick = askInt("Choose an option (0 = cancel)");
        if (pick == 0) { System.out.println("Cancelled."); return; }
        if (pick < 1 || pick > rec.size()) throw new InvalidInputException("No such option");
        Algorithms.SeatGroup g = rec.get(pick - 1);
        List<int[]> seats = new ArrayList<>();
        for (int c = 0; c < g.size; c++) seats.add(new int[]{g.row, g.startCol + c});
        String buyer = ask("Buyer name");
        TicketType type = askTicketType();
        List<Ticket> res = booking.book(s.getId(), seats, buyer, type);
        sys.save(DATA_FILE);
        System.out.println("Booking successful, " + res.size() + " ticket(s):");
        printTickets(res);
    }

    static void refund() throws CinemaException {
        Ticket t = booking.refund(askInt("Ticket id"));
        sys.save(DATA_FILE);
        System.out.println("Refund done: ticket " + t.getId() + ", " + Fmt.money(t.getPrice()) + " returned, seat released.");
    }

    static void findTickets() throws CinemaException {
        String m = ask("Search by (1 movie name, 2 buyer)");
        List<Ticket> list;
        if (m.equals("1")) list = booking.ticketsByMovieKeyword(ask("Movie name (or part of it)"));
        else if (m.equals("2")) list = booking.ticketsByBuyer(ask("Buyer name"));
        else throw new InvalidInputException("Choose 1 or 2");
        if (list.isEmpty()) System.out.println("(no tickets)");
        else printTickets(list);
    }

    // ------------------------------------------------------------------ statistics
    static void statScreenings() throws CinemaException {
        String hs = ask("Hall id (blank = all halls)");
        Hall h = hs.isEmpty() ? null : sys.getHall(parseIntOrThrow(hs));
        String ds = ask("Date yyyy-MM-dd (blank = all dates)");
        LocalDate d = ds.isEmpty() ? null : parseDate(ds);
        List<StatsService.ScreeningRow> rows = stats.screeningRows(h, d);
        if (rows.isEmpty()) { System.out.println("(no screenings)"); return; }
        System.out.println("Id | Time | Movie | Cinema / Hall | Adult price | VIP price | Sold/Cap | Occupancy | Revenue");
        for (StatsService.ScreeningRow r : rows) {
            Screening s = r.s();
            System.out.printf("#%d | %s | %s | %s / %s | %s | %s | %d/%d | %.1f%% | %s%n", s.getId(), Fmt.dt(s.getStart()), s.getMovie(),
                    sys.cinemaOf(s.getHall()).getName(), s.getHall().getName(), Fmt.money(r.normalPrice()), Fmt.money(r.vipPrice()),
                    r.sold(), r.capacity(), r.occupancy(), Fmt.money(r.revenue()));
        }
    }
    static int parseIntOrThrow(String s) throws InvalidInputException {
        try { return Integer.parseInt(s); }
        catch (NumberFormatException e) { throw new InvalidInputException("\"" + s + "\" is not a valid integer"); }
    }

    static void statHallsCinemas() {
        System.out.println("Revenue (refunds deducted):");
        double total = 0;
        for (Cinema c : sys.getCinemas()) {
            System.out.printf("%s: %s%n", c.getName(), Fmt.money(stats.cinemaRevenue(c)));
            for (Hall h : c.getHalls()) System.out.printf("    %s [%s]: %s%n", h.getName(), h.getType().getLabel(), Fmt.money(stats.hallRevenue(h)));
            total += stats.cinemaRevenue(c);
        }
        System.out.println("Total revenue: " + Fmt.money(total));
    }

    static void statMovies() {
        System.out.println("Box office of every movie:");
        for (StatsService.MovieRow r : stats.movieRows())
            System.out.printf("%s | tickets %d | box office %s%n", r.movie(), r.tickets(), Fmt.money(r.revenue()));
        System.out.println("Top 3 highest-grossing movies (min-heap Top-K):");
        int i = 1;
        for (StatsService.MovieRow r : stats.topMovies(3))
            System.out.printf("#%d %s | box office %s | tickets %d%n", i++, r.movie(), Fmt.money(r.revenue()), r.tickets());
    }

    static void statOccupancy() {
        System.out.println("Cinemas ranked by seat occupancy over all scheduled screenings:");
        int i = 1;
        for (StatsService.CinemaRow r : stats.topCinemasByOccupancy(sys.getCinemas().size()))
            System.out.printf("#%d %s | occupancy %.1f%% (%d/%d) | revenue %s%n", i++, r.cinema().getName(), r.occupancy(), r.sold(), r.capacity(), Fmt.money(r.revenue()));
    }

    // ------------------------------------------------------------------ administration
    static void addMovie() throws CinemaException {
        String name = ask("Movie name");
        int dur = askInt("Duration (minutes)");
        double price = askDouble("Base price");
        Movie m = schedule.addMovie(name, dur, price);
        sys.save(DATA_FILE);
        System.out.println("Movie added: " + m + ", id " + m.getId());
    }

    static void addScreening() throws CinemaException {
        listMovies();
        int mid = askInt("Movie id");
        Hall h = askHall();
        LocalDateTime start = askDateTime("Start time (yyyy-MM-dd HH:mm)");
        Screening s = schedule.addScreening(mid, h.getId(), start);
        sys.save(DATA_FILE);
        System.out.println("Screening added: #" + s.getId() + " " + s.getMovie() + " in " + sys.cinemaOf(h).getName() + " / " + h.getName()
                + ", " + Fmt.dt(s.getStart()) + "-" + Fmt.time(s.end()));
    }

    static void findSlot() throws CinemaException {
        listMovies();
        Movie m = sys.getMovie(askInt("Movie id"));
        Hall h = askHall();
        LocalDateTime earliest = askDateTime("Earliest start (yyyy-MM-dd HH:mm)");
        LocalDateTime slot = schedule.earliestSlot(m, h, earliest);
        System.out.println("Earliest slot for " + m + " in " + sys.cinemaOf(h).getName() + " / " + h.getName() + ": "
                + Fmt.dt(slot) + " (ends " + Fmt.time(slot.plusMinutes(m.getDurationMin())) + ")");
        if (ask("Create this screening now? (y/n)").equalsIgnoreCase("y")) {
            Screening s = schedule.addScreening(m.getId(), h.getId(), slot);
            sys.save(DATA_FILE);
            System.out.println("Screening created: #" + s.getId());
        }
    }
}
