import java.util.Scanner;
import java.io.*;

public class Burglary {
	public static void main(String args[]) throws IOException {
		Scanner scan = new Scanner(new File("burglary.dat"));

		int T = scan.nextInt();

		while (T-- > 0) {
			int N = scan.nextInt();

			double[] vals = new double[N];
			for (int i = 0; i < N; i++) {
				vals[i] = scan.nextDouble();
			}
			int best = 0;
			double bestVal = vals[0];
			double P = 1.00;
			int i = 0;
			double sum = vals[i];
			while (P > 0) {
				P -= 0.05;
				i++;
				if (i >= vals.length) break;
				sum += vals[i];
				double newval = P * sum;
				if (newval > bestVal) {
					bestVal = newval;
					best = i;
				}
			}
			System.out.printf("%d %.2f\r\n", best, bestVal);
		}

		scan.close();
	}
}
