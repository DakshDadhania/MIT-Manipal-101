/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication16;

/**
 *
 * @author student
 */
import java.util.Scanner;
public class JavaApplication16 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
       int org,r,sum=0;
       Scanner sc = new Scanner(System.in);
       System.out.println("Enter an int number:");
       int n = sc.nextInt();
       org = n;
       while (org != 0)
        {
            r= org % 10;
            sum+= Math.pow(r, 3);
            org/= 10;
        }
        if(sum==n)
            System.out.println(n + " is an Armstrong number.");
        else
            System.out.println(n+ " is not an Armstrong number.");
    }
}
