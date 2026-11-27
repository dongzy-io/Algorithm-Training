package java_code.experiment2;
import java.util.Objects;

public class commodity_system{
    static class Product{
        String name;
        double price;
        double mass;
        int piece_num;
        String manufacturer;
        Product(String name, double price, double mass, int piece_num, String manufacturer) {
            this.name=name; 
            this.price=price; 
            this.mass=mass; 
            this.piece_num=piece_num;
            this.manufacturer=manufacturer;
        }
        @Override
        public String toString() {
            return name+"\t"+price+"$\t"+mass+"g\t"+"has "+piece_num+" pieces\t"+manufacturer;
        }
        @Override
        public boolean equals(Object obj){
            if(this==obj) return true;
            if(obj==null||getClass()!=obj.getClass()) 
                return false;
            Product other=(Product)obj;
            return Objects.equals(name, other.name)&&Objects.equals(manufacturer, other.manufacturer)&&
                   Double.compare(price, other.price)==0&&Double.compare(mass, other.mass)==0&&
                   piece_num==other.piece_num;
        }
    }

    public static void main(String[] args){
        Product A=new Product("GUGUGAGA", 12.3, 11.1, 5, "Soney");
        Product B=new Product("MAKABAKA", 13.4, 22.2, 7, "Apple");
        Product C=new Product("GUGUGAGA", 12.3, 11.1, 5, "Soney");
        System.out.println(A);
        System.out.println(B);
        if(A.equals(B))
            System.out.println("SAME");
        else
            System.out.println("DIFFERENT");
        if(A.equals(C))
            System.out.println("SAME");
        else
            System.out.println("DIFFERENT");
    }
}