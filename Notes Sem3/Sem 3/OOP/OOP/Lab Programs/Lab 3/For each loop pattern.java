/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication18;

/**
 *
 * @author student
 */
public class JavaApplication18 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        
        int arr[]={1,2,3,4,5};  
        for(int i:arr)
        { 
            for(int j=1;j<=i;j++)
            {
                System.out.print(i);
            }
             System.out.print("\n");
        }  
    }
}
