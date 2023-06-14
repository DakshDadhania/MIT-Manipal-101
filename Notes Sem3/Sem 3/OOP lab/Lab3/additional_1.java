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
public class additional_1 {

        static void permute(int[] a, int k)
    {

        if (k == a.length)
        {
            for (int i = 0; i < a.length; i++) 
            {
                System.out.print(" [" + a[i] + "] ");
            }

            System.out.println();

        } 
        else 
        {
            for (int i = k; i < a.length; i++)
            {
                int temp = a[k];
                a[k] = a[i];
                a[i] = temp;

                permute(a, k + 1);

                temp = a[k];
                a[k] = a[i];
                a[i] = temp;
            }
        }

    }
    static void premuterep(int[] arr) {

        for(int i=1;i<5;i++){
            for(int j=1;j<5;j++) {
                for(int k=1;k<5;k++) {
                    for(int l=1;l<5;l++) {
                        System.out.println("["+i+"]"+" "+"["+j+"]"+" "+"["+k+"]"+" "+"["+l+"]"+" ");
                    }
                }
            }

        }
    }
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);

        int[] sequence = {1,2,3,4};
        int ans=0;
        System.out.println("The original sequence is: ");
        System.out.println("{1,2,3,4}");
        System.out.println("Case 1 or 2? ");
        ans=in.nextInt();
        System.out.println("\nThe permuted sequences are: ");
        if( ans==2)
          permute(sequence, 0);
        else if(ans==1)
            premuterep(sequence);
    }


}

