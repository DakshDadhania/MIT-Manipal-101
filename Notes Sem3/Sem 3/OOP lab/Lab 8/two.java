package Lab;//package Lab 8;

//import Lab.Calculator1;
//import Lab.Circle1;
//import Lab.Rectangle1;

import java.util.Scanner;

abstract class Calculator{
    double ar;
    abstract void area();
    void printer(){
        area();
        System.out.println(ar);
    }
}

class Rectangle extends Calculator{
    double length;
    double width;
    Rectangle(double l,double w){
        length=l;
        width=w;
    }
    void area(){
        ar = length*width;
    }
}

class Circle extends Calculator{
    double radius;
    Circle(double r){
        radius=r;
    }
    void area(){
        ar= 3.14*radius*radius;
    }
}

public class two{
        public static void main(String args[]){
            Scanner in =new Scanner(System.in);
            int l,b,c;
            System.out.println("Enter Length and breadth?");
            l=in.nextInt();
            b=in.nextInt();
            Calculator r= new Rectangle(l,b);
            System.out.println("area =" );r.printer();
            c=in.nextInt();
            r= new Circle(c);
            System.out.println("area =");r.printer();
        }
    }