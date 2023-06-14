import java.util.Scanner;

class runnableimplement implements Runnable
{
    public void run()
    {
        for(int i=0;i<5;i++)
            System.out.println("Runnable "+i);
    }
}
class Mythread extends Thread
{
    public void run()
        {
            System.out.println("Start");
            for(int i=0;i<5;i++)
            {
                System.out.println(i);}
            try
            {
                Thread.sleep(1000);
     
            }
            catch(Exception e)
            {
                System.out.println(e);
            }
            
            System.out.println("End");
        }
}
public class one 
{   
    public static void main(String[] args) throws InterruptedException 
    {
        Scanner in=new Scanner(System.in);
        Mythread t1=new Mythread();
       
        runnableimplement obj = new runnableimplement();
        System.out.println("Enter 0.Implement first and 1.Extend first");
        int choice=in.nextInt();
        if(choice==0){
        Thread t=new Thread(obj);
        t.start();
        Thread.sleep(1000);
        t1.start();
        
        }
        else{
            t1.start();
            Thread.sleep(1000);
            Thread t=new Thread(obj);
            t.start();
        }
        
       
        
    }    
}
