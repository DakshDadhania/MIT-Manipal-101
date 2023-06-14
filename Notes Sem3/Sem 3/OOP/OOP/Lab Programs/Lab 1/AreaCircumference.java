/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package areacircumference;
import java.util.Scanner;
/**
 *
 * @author student
 */
public class AreaCircumference {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.print("Enter the radius: ");
        Scanner s = new Scanner(System.in);
        double r = s.nextDouble();
        double area = 3.14*r*r; 
        double circumference = 2*3.14*r;
        System.out.println("Area is = " + area);
        System.out.println("Circumference is = " + circumference);
    }
    
}
