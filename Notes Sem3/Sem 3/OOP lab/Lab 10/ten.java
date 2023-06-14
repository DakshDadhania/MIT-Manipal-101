import java.util.Scanner;

class EvilNumber extends Exception{
    public String toString(){
        return "Evil Number! ";
    }
}

public class ten{
    public static void main(String args[]){
        try{
            Scanner in=new Scanner(System.in);
            System.out.println("Enter a 3 digit no");
            int n=in.nextInt();
           
            if(n>999)
                throw new EvilNumber();
            System.out.println(n);
        }
        catch(EvilNumber e){
            System.out.println(e+"No greater than 999");
        }
    }
}