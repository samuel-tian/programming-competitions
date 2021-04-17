import java.util.Scanner;
import java.io.*;

public class Christmas {
	public static void main(String args[]) throws IOException {
		Scanner scan = new Scanner(new File("christmas.dat"));

		int T = Integer.parseInt(scan.nextLine());

		while (T-- > 0) {
			int C = Integer.parseInt(scan.nextLine());

			int[] order = new int[3];
			for (int i = 0; i < C; i++) {
				String[] line = scan.nextLine().split("\\s+");
				for (int j = 0; j < 3; j++) {
					order[j] += Integer.parseInt(line[j]);
				}
			}

			int N = Integer.parseInt(scan.nextLine());

			String best = null;
			int bestPrice = Integer.MAX_VALUE;
			while (N-- > 0) {
				String[] line = scan.nextLine().split("\\s+");
				String name = line[0];
				int B = Integer.parseInt(line[1]);
				int S = Integer.parseInt(line[2]);
				int K = Integer.parseInt(line[3]);
				int P = Integer.parseInt(line[4]);
				// can't use this contractor to fufill the order
				if (B == 0 && order[0] != 0) continue;
				if (S == 0 && order[1] != 0) continue;
				if (K == 0 && order[2] != 0) continue;
				
				int numForBligs = getNumRequired(order[0], B);
				int numForSnorgs = getNumRequired(order[1], S);
				int numForKords = getNumRequired(order[2], K);
				// have to fufill all three, so the number total is the max of these
				int numCurrent = Math.max(numForBligs, Math.max(numForSnorgs, numForKords));
				int totalPrice = numCurrent * P;
				if (totalPrice < bestPrice) {
					//System.out.println("best: " + name + " " + numCurrent);
					bestPrice = totalPrice;
					best = name;
				} else if (totalPrice == bestPrice) {
					//System.out.println("tie: "+  name + " " + numCurrent);
				}
			}

			System.out.println(best + " " + bestPrice);
		}

		scan.close();
	}


	// returns the number of hours required to provide the right number of a certain toy
	public static int getNumRequired(int order, int contractor) {
		if (order == 0 && contractor == 0) return 0;
		// round up to next integer. integer divide, add one if there was a remainder
		return order / contractor + ((order % contractor != 0) ? 1: 0);
	}
}
