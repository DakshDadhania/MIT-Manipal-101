/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab3;

import java.util.Scanner;

/**
 *
 * @author student
 */
public class armstrong_1 {
       public static void main(String[] args){
           Scanner in=new Scanner(System.in);
           int a,rem=0,temp;
           long Sum=0;
           System.out.println("Prgm to check for armstrong no... Enter the no");
           
           
           char x=0;
           do{
           System.out.println("Enter the no");
           a=in.nextInt();
           temp=a;
           while(a!=0){
               rem=a%10;
               Sum=Sum+(rem*rem*rem);
               a=a/10;
           }
           if(Sum==temp){
               System.out.println("No is Armstrong Number");
           }
           else{
               System.out.println("No not a Armstrong Number");
           }
           System.out.println("continue? y/n");
           x=in.next().trim().charAt(0);
       }while(x=='y');
       }
}
