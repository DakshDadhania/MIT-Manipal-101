/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Lab1;
import java.util.Scanner;
/**
 *
 * @author student
 */
class area {
    int area;
    int l;
    area(int l, int b) {
        this.l=l;
        area = l * b;

    }
   int print(){
    return area;
}
}
public class Areaandcircumference {
     public static void main(String[] args) {
       Scanner in=new Scanner(System.in);
    
    System.out.println("Enter length and breadth of rectangle");  
    int length=in.nextInt();
    int breadth=in.nextInt();
    area a1=new area(length,breadth);

    System.out.println("Area"+a1.print());
//    int circum=2*(length+breadth);
//     System.out.println(circum);
     }

}
