package add;

import java.util.Scanner;

class NegativeArraySizeException extends Exception{
    public NegativeArraySizeException (String s){
        super(s);
    }
}

public class two {
    
     static void validate(int num)throws NegativeArraySizeException{
        if(num < 0){
            throw new NegativeArraySizeException("Negative Array Size not possible");
        }else{
            System.out.println("Array Size validated");
        }
    }
    public static void main(String args[]){
        Scanner sc = new Scanner (System.in);
        System.out.println("Enter size of an array ");
        int num = sc.nextInt();
        try{
            validate(num);
        }catch(NegativeArraySizeException ex){
            System.out.println("Caught Exception: Array Size is negative");
        }
        
        int array[];
        array = new int[num];
        for(int i = 0 ; i < num ; i++){
            array[i] = sc.nextInt();
        }
        for(int i = 0 ; i < num ; i++){
            System.out.print(array[i]+ " ");
        }
        System.out.println("");
        sc.close();
    }
}