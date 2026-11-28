# Cinema Booking System (console, Java)

Requires JDK 17 or newer (developed and tested with JDK 21).

## Build and run

    javac -encoding UTF-8 -d out src/cinema/*.java
    java -Dfile.encoding=UTF-8 -Dstdout.encoding=UTF-8 -cp out cinema.Main

`run.bat` (Windows) and `run.sh` (Linux/macOS) only run these two commands for you; you can ignore them
when you start the program from an IDE (run class `cinema.Main`).

Data is stored in `cinema.dat` in the working directory (created on first start, loaded automatically
afterwards). Delete the file to get the sample data again.

## Self-check (optional)

    javac -encoding UTF-8 -cp out -d out test/cinema/SelfCheck.java
    java -cp out cinema.SelfCheck

Compares the algorithms and the revenue ledger with brute-force versions on random inputs.

## Source layout (package `cinema`)

| Layer | Classes |
|---|---|
| UI | Main |
| Services | ScheduleService, BookingService, StatsService, CityService |
| Data container | CinemaSystem (persistence), Ledger (incremental revenue counters), SampleData |
| Algorithms | Algorithms |
| Entities | City, Cinema, Hall, Seat / NormalSeat / VipSeat, Movie, Screening, Ticket, HallType, TicketType, Priced |
| Exceptions | CinemaException and 7 subclasses |

## Weekly queries (main menu item 7)

The system works in 7-day weeks counted from a week base (sample data: Sat 2026-11-28) and the current week
follows the simulated clock. For every query the time slot defaults to the current week; a slot can be typed as
a date (`2026-11-29`, end = end of that day) or a date-time (`2026-11-29 18:00`). Screenings are selected by start time.

| Menu | Given | Result |
|---|---|---|
| 1 | cinema + time slot | all movies in the slot with hall, prices, sold/capacity, occupancy |
| 2 | cinema + movie | all showtimes of the movie in the cinema with hall and occupancy, per-day counts |
| 3 | movie + time slot | every cinema showing it (grid location), with halls, showtimes, occupancy |
| 4 | buyer (or all) + time slot | tickets bought for the week (valid / refunded, total price) |
| 5 | - | shows the current week |
