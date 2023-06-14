import java.util.*;
import java.lang.Math;
import java.text.DecimalFormat;

public class tracenorm {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        float arr[][] = new float[30][30];

        System.out.print("input dimensions: ");
        int n = sc.nextInt();

        System.out.println("input array: ");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = sc.nextFloat();
            }
        }

        float sum = 0, sumofsquares = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    sum += arr[i][j];
                }
                sumofsquares += arr[i][j] * arr[i][j];
            }
        }

        DecimalFormat df = new DecimalFormat("###.##");

        System.out.println("trace = " + sum);
        System.out.println("norm = " + df.format(Math.sqrt(sumofsquares)));

        sc.close();
    }
}
