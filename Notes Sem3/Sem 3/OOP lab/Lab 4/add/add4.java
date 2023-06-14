package add;

import java.util.Scanner;

public class add4 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the no of elemetns in 1st array");
        int n=in.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++){
            a[i]=in.nextInt();
        }
        System.out.println("Enter the no of elemetns in 2nd array");
        int m=in.nextInt();
        int b[]=new int[m];
        for(int i=0;i<m;i++){
            b[i]=in.nextInt();
        }
        int j=0;
        int c[]=new int[n+m];
        for(int i=0;i<n+m;i++){
            if(i<n){
                c[i]=a[i];
            }
            else{
                c[i]=b[j++];
            }
        }
//        for(int i=0;i<n+m-1;i++){
//            for(int j=0;j<n+m-i-1;j++){
//                if(c[i]>c[j]){
//                    int temp=0;
//                    temp=c[i];
//                    c[]
//                }
//            }
//        }
    }
}
