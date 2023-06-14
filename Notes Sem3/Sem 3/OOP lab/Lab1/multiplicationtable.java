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
public class multiplicationtable {
     public static void main(String[] args) {
       Scanner in=new Scanner(System.in);
       System.out.println("Enter a no to print it's multiplication table");
       int no=in.nextInt();
       for(int i=1;i<=10;i++){
         System.out.println(no+"X"+i+"="+(no*i));
       }
    }
}
