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
public class factorial {
     public static void main(String[] args) {
       Scanner in =new Scanner(System.in);
       System.out.println("Enter a no to print it's factorial");
       int fact=1;
       int no=in.nextInt();
       for(int i=no;i>1;i--){
           fact=fact*i;
       }
       System.out.println("Factorial is "+fact);
    }
}
