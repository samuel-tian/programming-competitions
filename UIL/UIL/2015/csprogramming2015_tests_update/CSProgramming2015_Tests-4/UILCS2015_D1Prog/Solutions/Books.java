import java.io.File;
import java.util.Arrays;
import java.util.Scanner;

public class Books {
    public static void main(String[] args) throws Exception {
        new Books().run();
    }

    public void run() throws Exception {
        Scanner in = new Scanner(new File("books.dat"));
        int cases = in.nextInt();
        for (int i = 0; i < cases; i++) {
            double K = in.nextDouble();
            int N = in.nextInt();
            double[] weights = new double[N];
            for (int j = 0; j < N; j++) {
                weights[j] = in.nextDouble();
            }
            Arrays.sort(weights);
            int count = 0;
            double sum = 0;
            for (int j = 0; j < N; j++) {
                sum += weights[j];
                if(sum > K)
                    break;
                count++;
            }
            System.out.println(count);
        }
    }
}
