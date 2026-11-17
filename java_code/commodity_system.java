package java_code; 

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
        public String toString() { return name+"\t"+price+"$\t"+mass+"g\t"+"has "+piece_num+" pieces\t";}
        boolean equals(Product other){
            return this.name.equals(other.name)&&this.manufacturer.equals(other.manufacturer)&&
                   this.price==other.price&&this.mass==other.mass&&
                   this.piece_num==other.piece_num;
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
    }
}