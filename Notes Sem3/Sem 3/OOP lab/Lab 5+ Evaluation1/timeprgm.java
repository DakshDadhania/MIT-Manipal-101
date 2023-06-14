
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author student
 */
class Time{
    int hours,minutes,seconds;
    Time(){
        this.hours=0;
        this.minutes=0;
        this.seconds=0;
    }
    Time(int h,int m,int s){
        this.hours=h;
        this.minutes=m;
        this.seconds=s;
        
    }
    void display(){
        System.out.println(this.hours+":"+this.minutes+":"+this.seconds);
    }
    void add(Time t1,Time t2){
        
        int s=t1.seconds+t2.seconds;
        int m=t1.minutes+t2.minutes;
        int h=t1.hours+t2.hours;
        this.seconds=s%60;
        this.minutes=(m+s/60)%60;
        this.hours=(h+m/60)%24;
    }
    
}
public class timeprgm {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        
        
        int h,h2,m,m2,s,s2;
        System.out.print("Enter hour,minute,second");
        h=in.nextInt();
        m=in.nextInt();
        s=in.nextInt();
        Time t2=new Time(h,m,s);
        t2.display();
        System.out.print("Enter hour,minute,second to be added");
        h2=in.nextInt();
        m2=in.nextInt();
        s2=in.nextInt();
        Time t3=new Time(h2,m2,s2);
        t3.display();
        System.out.println("Total time=");
        Time t4=new Time();
        t4.add(t2,t3);
        t4.display();
        
    }
}
