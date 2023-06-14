/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Lab3;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.stream.IntStream;

/**
 *
 * @author student
 */
public class search_6 {
    public static void main(String[] args){
        Scanner in =new Scanner(System.in);

        int[] arr = {1,2,3,1,2,1,5,6,7};
        System.out.println("a[]={1,2,3,1,2,1,5,6,7} SearchValue=");
        int a=in.nextInt();

         ArrayList<Integer> ans = new ArrayList<>();
        int c=0;
        for(int i:(arr)){
            if(i==a){
              ans.add(c);  
            }
            c++;
        }
        
        System.out.println("Element found at");
        for (int k : ans) {
            System.out.println("a[" + k + "]");
        }


    }
}
