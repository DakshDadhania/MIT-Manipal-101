import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author student
 */
class Complex{
    double[] sum=new double[2];
    Complex(int i1, int i2){
        this.sum[0]=i1;
        this.sum[1]=i2;
    }
    Complex(int i1, double[] d){
        this.sum[0]=i1+d[0];
        this.sum[1]=d[1];
    }
    Complex(double[]d1, double[] d2){
        this.sum[0]=d2[0]+d1[0];
        this.sum[1]=d2[1]+d1[1];
    }
    Complex(int i1, Complex x1){
        this.sum[0]=i1+x1.sum[0];
        this.sum[1]=x1.sum[1];
    }
    Complex(Complex i1, Complex x1){
        this.sum[0]=i1.sum[0]+x1.sum[0];
        this.sum[1]=i1.sum[1]+x1.sum[1];
    }
    void printer(){
        System.out.println(this.sum[0]+"+i"+this.sum[1]);
    }
}


   
public class complex2 {
     public static void main(String args[]){
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the Nos of first complex no");
        int n1,n2;
        n1=in.nextInt();
        n2=in.nextInt();
        Complex c0=new Complex(n1,n2);
        c0.printer();
        System.out.println("Enter the Nos of second complex no");
        int i1,i2;
        i1=in.nextInt();
        i2=in.nextInt();
        Complex c1=new Complex(i1,i2);
        c1.printer();
        System.out.println("The sum is =");
        Complex c2=new Complex(c0,c1);
        c2.printer();
    }

    
}

