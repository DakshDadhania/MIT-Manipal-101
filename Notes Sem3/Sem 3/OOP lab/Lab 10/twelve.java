import java.math.*;
import java.util.Scanner;
class NegativeNumber extends Exception{
    public String toString(){
        return "Can't calculate for Negative Numbers";
    }
}

public class twelve{
    public static void main(String args[]){
        try{
            System.out.println("Enter a no to calculate square root");
            Scanner in=new Scanner(System.in);
            int n=in.nextInt();
            if(n<0)
                throw new NegativeNumber();
            System.out.println(Math.sqrt(n));
        }
        catch(NegativeNumber e){
            System.out.println(e);
        }
    }
}