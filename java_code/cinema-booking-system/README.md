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
