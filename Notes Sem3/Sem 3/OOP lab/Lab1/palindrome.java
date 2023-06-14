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
public class palindrome {
    public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
       System.out.println("Enter a number to check if it's a palindrome");
       int a=in.nextInt();
       int temp=a;
       int rev = 0;
       while(a!=0){
           rev=rev*10+(a%10);
           a=a/10;
           }
       if(rev==temp){
           System.out.println("It's a palindrome");
       }
       else{
            System.out.println("It's not a palindrome");
       }
    }
}
