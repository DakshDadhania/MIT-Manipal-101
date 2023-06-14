/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package palindrome;
import java.util.Scanner;
/**
 *
 * @author student
 */
public class Palindrome {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.print("Enter the number: ");
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int rem, temp=n, rev=0;
        while(temp!=0){
            rem = temp%10;
            rev = (rev*10)+rem;
            temp/=10;
        }
        if (rev==n){
            System.out.println(n+" is a Palindrome");
        }
        else{
            System.out.println(n+" is not a Palindrome");
        }
    }
    
}
