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
public class patternadditional_3 {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int n;
        System.out.print("Enter no for pattern :");
        n=in.nextInt();
        System.out.println("Using nested for loop");
        int Count=1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<i;j++){
                System.out.print(Count+" ");
                Count++;
            }
            System.out.println();   
        }
        
      
    }
    
}


