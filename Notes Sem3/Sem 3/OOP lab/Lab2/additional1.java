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
public class additional1 {
    public static void main(String[] args) {
       Scanner in =new Scanner(System.in);
       System.out.println("Enter 2 nos");
       int a=in.nextInt();
       int b=in.nextInt();
       System.out.println(a>>2);
       System.out.println(((a << 2) + (b >> 2)) +" "+((b > 0)) +" "+ ((a + b * 100) / 10) +" "+( a & b));
    
    }
}
