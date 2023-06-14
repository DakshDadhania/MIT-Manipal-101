import java.util.Scanner;

public class nonpdia {
    /**
     * @param args
     */
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        System.out.print("Prgm to display and find sum of non principle dia");
    
        int a[][]=new int[10][10];
        System.out.println("Enter order of matrix");
        int n=in.nextInt();
        System.out.println("Order is"+n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=in.nextInt();
            }
        }
        int Sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==n-i-1)
                {
                System.out.print(a[i][j]);
                Sum+=a[i][j];
                }
            }
            System.out.println();
        }
        System.out.println("Sum is "+Sum);
        
        in.close();
    }
}

