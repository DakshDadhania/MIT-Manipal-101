/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package oddeven;
import java.util.Scanner;
/**
 *
 * @author student
 */
public class OddEven {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        for (int i=1; i<=100; i++){
            if (i%2!=0){
                System.out.print(i+ " ");
            }
        }
    }
    
}
