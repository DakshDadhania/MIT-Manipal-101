/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Lab2;

import java.util.Scanner;

/**
 *
 * @author student
 */
public class calculator {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        System.out.println("This is a 4 function calculator");
        
        float a,b,ans;
        char c;
        
        char x = 0;
        do{
            System.out.println("Enter no(space)(operand)(space)no");
            a=in.nextFloat();
            c=in.next().trim().charAt(0);
            b=in.nextFloat();
        switch(c){
            case('+'):{
                ans=a+b;
            System.out.println("Ans: "+ans);
                break;
            }
            case('-'):{
                ans=a-b;
            System.out.println("Ans: "+ans);
                break;
            }
            case('*'):{
                ans=a*b;
            System.out.println("Ans: "+ans);
                break;
            }
            case('/'):{
                ans=a/b;
            System.out.println("Ans: "+ans);
                break;
            }
            default:{
                System.out.println("Invalid input ");
                break;
            }
        }
        System.out.println("Do you want to continue: y/n? ");
        x=in.next().trim().charAt(0);
        }while(x=='y');
        
        
    }

 
}
