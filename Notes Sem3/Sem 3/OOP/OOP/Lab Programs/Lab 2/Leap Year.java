/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication11;

/**
 *
 * @author student
 */
import java.util.Scanner;
public class JavaApplication11 
{

    /**
     * @param args the command line arguments
     */
   public static void main(String[] args)
   {
        int year;
    	Scanner sc = new Scanner(System.in);
    	System.out.println("Enter any Year:");
    	year = sc.nextInt();
        boolean leap;
        if(year%4!=0)
            leap=false;
        else if(year%100!=0)
            leap=true;
        else if (year%400!=0)
            leap = true;
        else
            leap = false;
          
        if(leap==true)
            System.out.println(year + " is a Leap Year.");
        else
            System.out.println(year + " is not a Leap Year.");
    }
}