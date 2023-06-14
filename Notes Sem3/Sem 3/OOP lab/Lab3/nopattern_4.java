/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab3;

import java.util.Scanner;
import java.util.stream.IntStream;

/**
 *
 * @author student
 */
public class nopattern_4 {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int n;
        System.out.print("Enter no for pattern :");
        n=in.nextInt();
        System.out.println("Using nested for loop");
        for(int i=0;i<=n;i++){
            for(int j=0;j<i;j++){
                System.out.print(i);
            }
            System.out.println();   
        }
        
        int[] arr = IntStream.range(0, n+1).toArray();
        
  
    System.out.print("Using for each loop");
    for(int i:arr){
        for(int j:(IntStream.range(0, i).toArray())){
            System.out.print(i);
        }
    System.out.println();
    }
    }
}
