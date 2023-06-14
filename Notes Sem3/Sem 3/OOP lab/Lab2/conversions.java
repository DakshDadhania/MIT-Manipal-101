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
public class conversions {
    public static void main(String[] args) {
        System.out.println("Enter nos for conversion");
        Scanner in=new Scanner(System.in);
        int no1=in.nextInt();
        double no2=in.nextDouble();
        char ch  = in.next().charAt(0);
        
        System.out.println((byte)no1+" "+(int)ch+" "+(byte)no2+" "+(int)no2);
    }
}
