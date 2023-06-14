package add;

import java.util.Scanner;

public class add2 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int a[]=new int[100];
        System.out.println("Enter elements in array");
        int n=in.nextInt();
        int largest=0;
        int smallest=2147483647;
        for(int i=0;i<n;i++){
            a[i]=in.nextInt();
            if(a[i]<smallest){
                smallest=a[i];
            }
            if(a[i]>largest){
                largest=a[i];
            }
        }
        System.out.println("Largest ="+largest+" "+"Smallest ="+smallest);
        in.close();
    }
}
