import java.util.Scanner;
class Counter{
    static int count=0;
    Counter(){
        count+=1;
    }
    void displayCount(){
        System.out.println(count);
    }
}

public class two{
    public static void main(String args[]){
        Counter c1, c2, c3;
        c1=new Counter();
        c2=new Counter();
        c3=new Counter();
        
        System.out.println("No. of objects created:"+Counter.count);
    }
}