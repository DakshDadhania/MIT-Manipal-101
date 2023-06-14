/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication12;

/**
 *
 * @author student
 */
import java.util.Scanner;
public class JavaApplication12 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
    	System.out.println("Enter an int number:");
    	int n = sc.nextInt();
        System.out.println("Enter a double number:");
    	double d = sc.nextInt();
        System.out.println("Enter a character:");
    	char c = sc.next().charAt(0);
        byte a=(byte)n;
        int b=(int)c;
        byte e=(byte)d;
        int t=(int)d;
        System.out.println("int to byte: "+a);
        System.out.println("char to int: "+b);
        System.out.println("double to byte: "+e);
        System.out.println("double to int: "+t);   
    }
}
