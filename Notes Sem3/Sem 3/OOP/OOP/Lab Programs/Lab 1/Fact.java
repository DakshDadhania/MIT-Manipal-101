/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fact;
import java.util.Scanner;

/**
 *
 * @author student
 */
public class Fact {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.print("Enter the number:");
        Scanner s = new Scanner(System.in);
        int n=s.nextInt();
        int i;
        int factorial=1;
        
        for (i=2; i<=n; i++){
            factorial= factorial*i;
        }
        System.out.println(factorial);
    
    }
    
}
