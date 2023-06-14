import java.util.Scanner;

public class addmul {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int matrix1[][]=new int[10][10];
        int matrix2[][]=new int[10][10];
        int add[][]=new int[10][10];
        int mul[][]=new int[10][10];
    
        System.out.println("Enter the order of matrix");
        int n=in.nextInt();
        System.out.println("Enter matrix 1");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix1[i][j]=in.nextInt();
            }
        }
        System.out.println("Enter matrix 2");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix2[i][j]=in.nextInt();
            }
        }
        System.out.println("Addition of matrices");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                add[i][j]=matrix1[i][j]+matrix2[i][j];
                System.out.print(add[i][j]+" ");
            }
            System.out.println();
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

               mul[i][j]=0;
               mul[i][j]=matrix1[i][j]*matrix2[j][i];
            }
          
        }
        System.out.println("Multiplication of matrices");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                System.out.print(mul[i][j]+" ");
            }
            System.out.println();
        }

        in.close();

    }
}
