/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Lab1;

/**
 *
 * @author student
 */
public class oddnos {
     public static void main(String[] args) {
     System.out.println("Generating odd nos from 1 to 100");
        for(int i=1;i<=100;i++){
        if(i%2==0){
        continue;
        }
        else{
            System.out.println(i);
        }
    }  
     } 
}
