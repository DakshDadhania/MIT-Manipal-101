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
public class primenos {
    public static void main(String[] args){
       Scanner in=new Scanner(System.in);
        int n,m;
        System.out.println("Enter n and m btwn which you want primes nos to be printed");
        n=in.nextInt();
        m=in.nextInt();
        for(int i=n;i<=m;i++){
            int Count=0;
           
            for( int c=2;c*c<=i;c++){
               if(i%c==0){
                   Count++;
               }
                
            }
            if(Count==0){
                System.out.println(i);
            }
            
        }
       
    }
}
