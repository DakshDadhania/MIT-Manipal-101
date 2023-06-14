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
public class bitwiseshift {
    public static void main(String[] args) {
       Scanner in=new Scanner(System.in);
       System.out.println("Enter a no to multiply and divide by 2");
       int no=in.nextInt();
       System.out.println((no<<1)+" "+(no>>1));
    }
}
