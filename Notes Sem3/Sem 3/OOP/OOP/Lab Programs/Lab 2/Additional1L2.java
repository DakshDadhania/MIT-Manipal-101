/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.mycompany.mavenproject1;

/**
 *
 * @author niraj
 */
import java.util.Scanner;
public class Mavenproject1 {

    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a and b: ");
        int a=sc.nextInt();
        int b=sc.nextInt();
        
        int r1=(a<<2)+(b>>2);
        System.out.println("(a<<2)+(b>>2): "+r1);
        boolean r2=(b>0);
        System.out.println("(b>0): "+r2);
        int r3=(a+b*100)/10;
        System.out.println("(a+b*100)/10: "+r3);
        System.out.println("a & b: "+a+" & "+b);
    }
}
