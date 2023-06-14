/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Lab2;

import java.util.Scanner;

/**
 *
 * @author student
 */
public class leapyr {
    public static void main(String[] args) {
       System.out.println("Enter the year to check Leap or not"); 
       try (Scanner in = new Scanner(System.in)) {
        int year=in.nextInt();
           boolean leap=false;
           if(year%4!=0){
               leap=false;
           }
           else if(year%100!=0){
               leap=true;
           }
           else if(year%400!=0){
               leap=false;
           }
           else{
               leap=true;
           }
           
           if(leap){
               System.out.println("Its a leap year");
           }
           else{
               System.out.println("not a leap year");
        }
    }
    }
}
