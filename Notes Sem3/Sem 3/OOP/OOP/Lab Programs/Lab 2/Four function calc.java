/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication15;

/**
 *
 * @author student
 */
import java.util.Scanner;
public class JavaApplication15 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {  
        float ans;
        char ch;
        do
        {
        Scanner sc = new Scanner(System.in);
    	System.out.print("Enter first number, operator, second number: ");
    	int a = sc.nextInt();
     	char c = sc.next().charAt(0);
       	int b = sc.nextInt();
        switch(c)
        {
            case '+': 
                ans=a+b;
                break;
            case '-':
                ans=a-b;
                break;
            case '*':
                ans=a*b;
                break;
            case '/':
                ans=a/b;
                break;
            default:
                ans=0;
                
        }
        System.out.println("Answer: "+ans);
        System.out.print("Do another (y/n)?: ");
        ch = sc.next().charAt(0);
        }
        while(ch!='n');
    }
}
