/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package positiveneg;

import java.util.Scanner;

/**
 *
 * @author student
 */
public class PositiveNeg {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner s = new Scanner(System.in);
        int pos=0, neg=0, zero=0;
        for (int i=0; i<10; i++){
            System.out.print("Enter the number: ");
            int n = s.nextInt();
            if(n>0){
                pos++;
            }
            else if(n<0){
                neg++;
            }
            else if (n==0){
                zero++;
            }
            else{
                System.out.println("Give a valid number");
            }
        }
        System.out.println("positive numbers: "+ pos);
        System.out.println("negative numbers: "+ neg);
        System.out.println("zero numbers: "+ zero);
    }
    
}
