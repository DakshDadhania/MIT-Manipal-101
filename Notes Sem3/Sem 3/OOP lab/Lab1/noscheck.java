/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Lab1;

import java.util.Scanner;

/**
 *
 * @author student
 */
public class noscheck {
     public static void main(String[] args) {
      Scanner in=new Scanner(System.in);
    
    System.out.println("Enter 10 nos for +ve and -ve nos");  
        int[] nos;
        nos=new int[10];
    for(int i=0;i<10;i++){
        nos[i]=in.nextInt();
    }
    int positive=0;
    int negative=0;
    for(int i=0;i<10;i++){
        if(nos[i] >0){
            positive++;
        }
        else if(nos[i]<0){
            negative++;
        }
    }
    System.out.println("Positive nos "+positive+"Negative Nos "+negative);

         
     }
}
