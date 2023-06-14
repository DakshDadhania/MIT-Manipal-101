/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication21;



/**
 *
 * @author student
 */
import java.util.Scanner;
public class JavaApplication21 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
     Scanner sc = new Scanner(System.in);
     System.out.print("Enter number to be found: ");
     int n =sc.nextInt();
     int a[]={1,2,3,1,2,1,5,6,7};  
     boolean found = false;
     for (int i:a) 
     {
      if (i==n) 
      {
        found= true;
        break;
      }
    }
    if(found)
      System.out.println(n + " is found.");
    else
      System.out.println(n + " is not found.");
  }
}
