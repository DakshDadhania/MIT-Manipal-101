/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package table;
import java.util.Scanner;

/**
 *
 * @author student
 */
public class Table {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.print("Enter the number: ");
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int i;
        for ( i=1; i<=10; i++){
            int product = n*i;
            System.out.println(n + " * " + i + " = " + product);
        }
    }
    
}
