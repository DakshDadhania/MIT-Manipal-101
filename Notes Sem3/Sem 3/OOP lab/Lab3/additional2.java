/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab3;

import java.util.Scanner;

import static java.lang.Math.*;

/**
 *
 * @author student
 */
public class additional2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n;
        System.out.println("Enter no of terms till when you want to evaluate sin/sum series");
        n = in.nextInt();
        double deg;
        System.out.println("Enter value of theta(in deg)");
        deg = in.nextDouble();

        Series(n);

        Sin(deg, n);

    }

    static void Series(int n) {

        double sums = 0.0;
        for (int i = 1; i <= n; i++)
            sums += 1 / pow(i, i);
        System.out.println("Sum =" + sums);
    }

    static void Sin(double x, int n) {
        double y;
        y = x * PI / 180;
        int i, j, fac;
        double sine = 0;
        for (i = 0; i <= n; i++) {
            fac = 1;
            for (j = 2; j <= 2 * i + 1; j++) {
                fac *= j;
            }
            sine += pow(-1.0, i) * pow(y, 2 * i + 1) / fac;
        }
        System.out.println("The sine of " + x + " is " + sine);

    }

}
