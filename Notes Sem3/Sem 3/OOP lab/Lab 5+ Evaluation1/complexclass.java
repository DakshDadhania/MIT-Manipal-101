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
class Complex{
   double[] sum=new double[2];

   Complex(int i1, double[] d){
       this.sum[0]=i1+d[0];
       this.sum[1]=d[1];
   }
   Complex(double[]d1, double[] d2){
       this.sum[0]=d1[0]+d1[0];
       this.sum[1]=d2[1]+d1[1];
   }
   void printer(){
       System.out.println(this.sum[0]+"+i"+this.sum[1]);
   }
}



public class complexclass {
    public static void main(String args[]){
       Scanner in=new Scanner(System.in);
       double[] d1={22,22};
       Complex c1=new Complex(12,d1);
       c1.printer();
       double[] d2={34,55};
       Complex c2=new Complex(d2,d1);
       c2.printer();
       in.close();
   }


}
