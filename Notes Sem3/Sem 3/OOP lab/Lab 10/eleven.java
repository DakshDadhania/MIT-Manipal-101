import java.util.Scanner;
class eleven{
    public static void main(String args[]){
        try{
            Scanner in=new Scanner(System.in);
            System.out.println("Enter no of rows");
            int m=in.nextInt();
            System.out.println("Enter no of Columns");
            int n=in.nextInt();
           
            if(m!=n){
                throw new Exception();
            }
            int a[][]=new int[m][n];
            
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    a[i][j]= in.nextInt();
                }
            }
            System.out.println("Got the square matrix");
            
        }
        catch(Exception e){
            System.out.println("Not a square matrix");
            return;
        }
    }
}