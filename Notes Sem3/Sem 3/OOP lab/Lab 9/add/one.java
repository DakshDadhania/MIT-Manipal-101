package add;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;

public class one {
    
    static void arrange(String arr[], int n){
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < n-i-1; j++){
                if(arr[j].compareTo(arr[j+1]) > 0){
                String temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                }
            }
        }
    }
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of Array");
        int n = sc.nextInt();
        String temp = sc.nextLine();
        String arr[] = new String[n];
        System.out.println("Enter the Strings in the Array");
        for(int i = 0 ; i < n ; i++){
            arr[i] = sc.nextLine();
        }
        System.out.println("The Array in arranged form is : ");
        arrange(arr,n);
         for(int i = 0 ; i < n ; i++){
            System.out.println(arr[i]);
        }
        
        sc.close();
    }
}