import java.util.Scanner;

public class symmetric {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int transpose[][] = new int[10][10];
        int matrix[][] = new int[10][10];
        System.out.println("Enter order of matrix");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = in.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                transpose[i][j] = matrix[j][i];
            }
        }
        int Sount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == transpose[i][j])
                    Sount++;

            }
        }
        if (Sount == n * n)
            System.out.println("Symm");
        else
            System.out.println("Not Symmetric");

        in.close();

    }
}
