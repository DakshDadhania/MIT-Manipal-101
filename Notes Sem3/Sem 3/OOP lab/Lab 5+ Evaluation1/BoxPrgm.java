/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
class box{
    double width, height, depth,volume;
    box(){
        this.width=0;
            this.height=0;
            this.depth=0;
    }
    void Set(double width,double height,double depth ){
            this.width=width;
            this.height=height;
            this.depth=depth;
    }
   double volume() {
       volume=width*height*depth;
       return volume;
   }    
    
}
public class BoxPrgm {
       public static void main(String[] args){
           Scanner in=new Scanner(System.in);
           double width,height,depth;
           System.out.println("Enter Width Height and Depth of Box");
           width=in.nextDouble();
           height=in.nextDouble();
           depth=in.nextDouble();
           box b1=new box();
           b1.Set(width,height,depth);
           System.out.println("volume of box is "+b1.volume());
           
           
       }
}
