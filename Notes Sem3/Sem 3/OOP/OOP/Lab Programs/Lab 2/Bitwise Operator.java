/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication13;

/**
 *
 * @author student
 */
import java.util.Scanner;
public class JavaApplication13 {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
    	System.out.println("Enter a number: ");
    	int a = sc.nextInt();
        int m=a<<1;
        int d=a>>1;
        System.out.println("Multiplied by 2: "+m);
        System.out.println("Divided by 2: "+d);
    }
    
}
