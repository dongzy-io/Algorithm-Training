package java_code;
import java.util.Scanner;

public class Stars {
    static void printSpaces(int k) {
        for(int i=0; i<k; i++) {
            System.out.print(" ");
        }
    }

    static void printStars(int sp, int st) {
        printSpaces(sp);
        for (int i=0; i<st; i++) {
            System.out.print("* ");
        }
        System.out.println();
    }

    static void printUpper(int n) {
        for (int stars=1; stars<n; stars+=2) {
            printStars(n - stars, stars);
        }
    }

    static void printMiddle(int n) {
        printStars(0, n);
    }

    static void printLower(int n) {
        for (int stars=n-2; stars>=1; stars-=2) {
            printStars(n - stars, stars);
        }
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        if(n%2==1){
            printUpper(n);
            printMiddle(n);
            printLower(n);
        }else{
            System.out.println("EVEN NUMBER, CAN'T FORM A GRAPH!");
        }
        sc.close();
    }
}