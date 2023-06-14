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
public class areaandcir_2 {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        float a,b,ar,cir;
        System.out.println("Enter length and breadth of rectangle for area & circumference");
        a=in.nextFloat();
        b=in.nextFloat();
        ar=a*b;
        cir=2*(a+b);
        System.out.println("Area= "+ar+"  "+"Circumference="+cir);
    }
}
