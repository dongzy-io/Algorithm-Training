package java_code.experiment3;
import java.util.*;

abstract class shape{
    //private double radius;
    static double totalPerimeter=0;
    static double totalArea=0;
    public abstract double calcArea();
    public abstract double calcPerimeter();
    protected void register(){
        totalPerimeter+=calcPerimeter();
        totalArea+=calcArea();
    }
}

class circle extends shape{
    private double radius;
    circle(double r){
        this.radius=r;
        register();
    } 
    @Override 
    public double calcArea() {
        return Math.PI*radius*radius;
    }
    @Override 
    public double calcPerimeter(){
        return 2*Math.PI*radius;
    }
}

class square extends shape{
    private double a;
    square(double a){
        register();
    }
    @Override
    public double calcArea() {
        return a*a;
    }
    @Override 
    public double calcPerimeter(){
        return 4*a;
    }
}

class triangle extends shape{
    private double a,b,c;
    triangle(double a, double b, double c){
        this.a=a;
        this.b=b;
        this.c=c;
        register();
    }
    @Override 
    public double calcArea(){ 
        double p=(a+b+c)/2;
        return Math.sqrt(p*(p-a)*(p-b)*(p-c));
    }
    @Override
    public double calcPerimeter(){
        return a+b+c;
    }
}

public class shapes{
    public static void main(String args[]){
        List<shape> shapes=new ArrayList<>();
        shapes.add(new circle(10));
        shapes.add(new square(10));
        shapes.add(new square(20));
        shapes.add(new triangle(10, 10, 10));
        shapes.add(new triangle(10, 10, 15));

        System.out.println("所有图形：");
        for (shape s : shapes) {   
            System.out.println(s + "，面积是：" + s.calcArea() + "，周长是：" + s.calcPerimeter());
        }
        System.out.println("面积和是：" + shape.totalArea);
        System.out.println("周长和是：" + shape.totalPerimeter);
    }
}