package cinema;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.TextStyle;
import java.util.Locale;

/** Small formatting helpers shared by the services and the console UI. */
public final class Fmt{
    private Fmt() {}
    public static String time(LocalDateTime t) { 
        return String.format("%02d:%02d", t.getHour(), t.getMinute()); 
    }
    public static String dt(LocalDateTime t) {
        return t.getDayOfWeek().getDisplayName(TextStyle.SHORT, Locale.ENGLISH) + " "
                + String.format("%02d-%02d ", t.getMonthValue(), t.getDayOfMonth()) + time(t);
    }
    /** Short date with weekday, e.g. "Sat 11-28". */
    public static String day(LocalDate d) {
        return d.getDayOfWeek().getDisplayName(TextStyle.SHORT, Locale.ENGLISH) + String.format(" %02d-%02d", d.getMonthValue(), d.getDayOfMonth());
    }
    public static String money(double v) { return String.format("%.2f", v); }
}
