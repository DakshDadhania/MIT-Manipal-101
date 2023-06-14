/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication19;

/**
 *
 * @author student
 */
import java.util.Scanner;
public class JavaApplication19 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
    Scanner sc = new Scanner(System.in);
    int a,b,i,j,flag;
    System.out.print("Enter lower limit: ");
        a = sc.nextInt(); 
        System.out.print("\nEnter upper bound of the interval: ");
        b = sc.nextInt();
        System.out.print("\nPrime numbers between "+a+" and "+b+" are: ");
        for (i = a; i <= b; i++)
        {
            if (i == 1 || i == 0)
                continue;
            flag = 1;
            for (j = 2; j <= i / 2; ++j)
            {
                if (i % j == 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                System.out.print(i+" ");
        }
    }
}