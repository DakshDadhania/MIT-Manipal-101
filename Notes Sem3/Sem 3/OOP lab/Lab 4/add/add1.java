package add;

import java.util.Scanner;

public class add1{
    public static void main(String[] args) {
        Scanner in= new Scanner(System.in);
        int a[]=new int[100];
        System.out.println("Enter the size of array");
        int n=in.nextInt();
        for(int i=0;i<n;i++){
            System.out.print("a["+i+"] = ");
            a[i]=in.nextInt();
        }
        System.out.println("Prime nos are");
        for(int i=0;i<n;i++){
            int Count=0;
            for(int j=2;j<a[i];j++){
                if(a[i]%j==0){
                    Count++;
                }
            }
            if(Count==0){
                System.out.print(a[i]+" ");
            }
        }
        in.close();

    }
}
