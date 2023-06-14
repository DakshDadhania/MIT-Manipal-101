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
public class largestandsmallestbyternary {
    public static void main(String[] args) {
       Scanner in=new Scanner(System.in);
       System.out.println("Enter 3 nos");
       int a=in.nextInt();
       int b=in.nextInt();
       int c=in.nextInt();
       System.out.println((a>b)?((a>c)?a:c):((b>c)?b:c));
       System.out.println((a<b)?((a<c)?a:c):((b<c)?b:c));
    }
}
