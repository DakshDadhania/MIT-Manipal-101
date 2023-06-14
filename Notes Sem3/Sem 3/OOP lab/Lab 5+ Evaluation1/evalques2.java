/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package pkg210911072.lab.pkg5;

import static java.lang.Math.pow;
import java.util.Scanner;

/**
 *
 * @author student
 */
public class evalques2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n;
        long x;
        System.out.println("Enter x");
        x=in.nextLong();
        System.out.println("Enter n");
        n=in.nextInt();
        double Sum=1;
        for(int i=1;i<n;i++){
            if(i%2==0){
                Sum=Sum + (((2*i-1)*(pow(x,i)))/(pow(2,2*i-1)*fact(2*i)));
            }
            else if(i%2==1){
                Sum=Sum - (((2*i-1)*(pow(x,i)))/(pow(2,2*i-1)*fact(2*i)));
            }
           
        }
        System.out.println(Sum);
//         System.out.println(fact(5));
    }
    
    static int fact(int n){
        int ans=1;
        for(int i=n;i>1;i--){
            ans=ans*i;
        }
        return ans;
    }
}
