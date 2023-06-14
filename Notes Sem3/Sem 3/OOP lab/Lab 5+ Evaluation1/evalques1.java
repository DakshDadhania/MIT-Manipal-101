/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.Scanner;

/**
 *
 * @author student
 */
public class evalques1 {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int n;
        System.out.println("Enter decimal");
      
        n=in.nextInt();
        
        int ans=0;
        int rem=0;
        while(n>=1){
            rem=n%8;
            n=n/8;
            
            ans=ans*10+rem;
        }
        
       
        System.out.println(rev(ans));
        in.close();
    }
    static int rev(int ans){
        int rev=0;
        int rem;
        while(ans!=0){
            rem=ans%10;
            ans=ans/10;
            rev=rev*10+rem;
        }
        return rev;
    }
}
