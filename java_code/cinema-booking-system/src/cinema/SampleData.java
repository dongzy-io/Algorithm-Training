package cinema;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.Random;

/** Builds the sample data used on the first start: a city, four cinemas, a week of screenings. */
public final class SampleData {
    private SampleData() {}

    public static final LocalDate FIRST_DAY = LocalDate.of(2026, 11, 28);

    public static CinemaSystem build() {
        City city = new City(15, 20);
        for (int r = 0; r < 15; r++) if (r != 4 && r != 11) city.block(r, 9);   // a river with two bridges
        city.block(5, 5); city.block(5, 6); city.block(6, 5); city.block(6, 6);   // a block of buildings

        CinemaSystem sys = new CinemaSystem(city, FIRST_DAY.atTime(8, 0));
        ScheduleService schedule = new ScheduleService(sys);
        BookingService booking = new BookingService(sys);
        try {
            int[][] pos = {{3, 4}, {8, 14}, {12, 2}, {1, 16}};
            String[] names = {"Central Cinema", "Riverside Cinema", "Harbor Cinema", "North Plaza Cinema"};
            for (int i = 0; i < 4; i++) {
                sys.addCinema(new Cinema(i + 1, names[i], pos[i][0], pos[i][1]));
                city.placeCinema(i + 1, pos[i][0], pos[i][1]);
            }
            sys.addHall(new Hall(1, 1, "Hall A", HallType.STANDARD, 8, 10, 2, 4));
            sys.addHall(new Hall(2, 1, "Hall B", HallType.STANDARD, 6, 8, 2, 3));
            sys.addHall(new Hall(3, 2, "Hall A", HallType.STANDARD, 7, 10, 2, 4));
            sys.addHall(new Hall(4, 2, "IMAX Hall", HallType.IMAX, 10, 12, 3, 6));
            sys.addHall(new Hall(5, 3, "Hall A", HallType.STANDARD, 6, 8, 2, 3));
            sys.addHall(new Hall(6, 4, "Hall A", HallType.STANDARD, 6, 8, 2, 3));

            schedule.addMovie("Star Voyage", 128, 45);
            schedule.addMovie("Letter Box of Time", 112, 40);
            schedule.addMovie("Legends of the Mountain Sea", 135, 50);
            schedule.addMovie("Last Summer", 98, 35);
            schedule.addMovie("Midnight Chase", 105, 42);

            // one week of screenings: 4 slots per hall per day, movies rotate
            LocalTime[] slots = {LocalTime.of(9, 30), LocalTime.of(12, 40), LocalTime.of(16, 0), LocalTime.of(19, 20)};
            for (int h = 0; h < sys.getHalls().size(); h++)
                for (int d = 0; d < 7; d++)
                    for (int j = 0; j < slots.length; j++)
                        schedule.addScreening((h + d + j) % 5 + 1, h + 1, FIRST_DAY.plusDays(d).atTime(slots[j]));

            // some pre-sold tickets so that statistics are not empty (fixed random seed)
            Random rnd = new Random(7);
            for (Screening s : sys.getScreenings()) {
                int popularity = s.getMovie().getId() == 1 ? 20 : s.getMovie().getId() == 3 ? 12 : 0;
                int n = rnd.nextInt(10 + popularity);
                for (int i = 0; i < n; i++) {
                    int r = rnd.nextInt(s.getHall().getRows()), c = rnd.nextInt(s.getHall().getCols());
                    TicketType type = rnd.nextInt(10) < 3 ? TicketType.STUDENT : TicketType.ADULT;
                    try {
                        booking.book(s.getId(), java.util.List.of(new int[]{r, c}), "walk-in", type);
                    } catch (SeatOccupiedException ignored) { /* seat already taken: skip */ }
                }
            }
        } catch (CinemaException e) {
            throw new IllegalStateException("Sample data is inconsistent: " + e.getMessage(), e);
        }
        return sys;
    }
}
