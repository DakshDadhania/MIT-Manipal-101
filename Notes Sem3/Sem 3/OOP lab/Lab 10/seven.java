import java.io.*;
import java.util.Scanner;
class seven{
    public static void main(String args[]){
        try{
            Scanner in=new Scanner(System.in);
            System.out.println("Enter no");
            String n;
            n=in.nextLine();
            int a= Integer.parseInt(n);
            System.out.println(a);
        }
        catch(NumberFormatException e){
            System.out.println("Not a number");
        }
        finally{
            System.out.println("Exiting");
        }
    }
}