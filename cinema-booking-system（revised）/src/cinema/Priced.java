package cinema;

/** Something that can compute its own price from a base price. */
public interface Priced {
    double priceFor(double basePrice);
}
