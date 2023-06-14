package Lab;//package Lab 8;

import java.util.Scanner;

interface Calculator1{
    double area();
}

class Rectangle1 implements Calculator1{
    double length, breadth;
    Rectangle1(double l, double b){
        length=l;
        breadth=b;
    }
    public double area(){
        return length*breadth;
    }
}

class Circle1 implements Calculator1{
    double radius;
    Circle1(double r){
        radius=r;
    }
    public double area(){
        return 3.14*radius*radius;
    }
}

public class three {
    public static void main(String args[]){
        Scanner in =new Scanner(System.in);
        int l,b,c;
        System.out.println("Enter Length and breadth?");
        l=in.nextInt();
        b=in.nextInt();
        Calculator1 r= new Rectangle1(l,b);
        System.out.println("area ="+ r.area());
        c=in.nextInt();
        r= new Circle1(c);
        System.out.println("area ="+r.area());
    }
}