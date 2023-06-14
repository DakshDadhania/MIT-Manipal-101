package add;

import java.util.Scanner;

public class add3 {
    public static void main(String[] args) {
        int matrix[][]=new int [10][10];
        Scanner in=new Scanner(System.in);
        System.out.println("Enter order of matrix and element to be searched");
        int n=in.nextInt();
        int s=in.nextInt();
        System.out.println("Enter elements");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=in.nextInt();
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(s==matrix[i][j]){
                count++;
               }
            }
        }
        System.out.println("No of occur. "+count);
        in.close();
    }
}
