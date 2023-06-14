

import java.util.Scanner;

public class magic {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int a[][]=new int[10][10];
        System.out.println("Enter order of matrix");
        int n=in.nextInt();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=in.nextInt();
            }
        }
        int ans1=0;
        int ans2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)
                    ans1+=a[i][j];
                if(i==n-j-1){
                    ans2+=a[i][j];
                 }
            }
        }
        System.out.println(ans1+" "+ans2);
        if(ans1==ans2){
            int row[]=new int[10];
            int col[]=new int[10];
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                
                    row[i]+=a[i][j];
                    
                    col[j]+=a[i][j];
                    
                }
            }
            
            boolean magic=true;
            for(int i=0;i<n;i++){
                if(row[i]!=ans1){
                    magic=false;
                }
            }
            
            for(int i=0;i<n;i++){
                if(col[i]!=ans1){
                    magic=false;
                }
            }
           
            if(magic==true){
                System.out.println("Magic Matrix");
            }
            else{
                System.out.println("Not a magic matrix");
            }

        }
        else{
            System.out.println("Not a magic matrix");
        }
        in.close();
       
    }
}
