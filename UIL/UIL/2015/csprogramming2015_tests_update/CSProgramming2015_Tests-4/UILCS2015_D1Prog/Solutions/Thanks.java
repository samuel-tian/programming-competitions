import java.util.Scanner;
import java.io.*;

public class Thanks {
	public static void main(String args[]) throws IOException {
		Scanner scan = new Scanner(new File("thanks.dat"));

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
			int bestNum = Integer.MAX_VALUE;
			while (N-- > 0) {
				String[] line = scan.nextLine().split("\\s+");
				String name = line[0];
				int L = Integer.parseInt(line[1]);
				int A = Integer.parseInt(line[2]);
				int B = Integer.parseInt(line[3]);
				// can't use this species to fufill the order
				if (L == 0 && order[0] != 0) continue;
				if (A == 0 && order[1] != 0) continue;
				if (B == 0 && order[2] != 0) continue;
				
				int numForLegs = getNumRequired(order[0], L);
				int numForArms = getNumRequired(order[1], A);
				int numForBreast = getNumRequired(order[2], B);
				// have to fufill all three, so the number total is the max of these
				int numCurrent = Math.max(numForLegs, Math.max(numForArms, numForBreast));
				if (numCurrent < bestNum) {
					bestNum = numCurrent;
					best = name;
				} 
			}

			System.out.println(best);
		}

		scan.close();
	}


	// returns the number of the species required to provide the right number of a certain part
	public static int getNumRequired(int order, int species) {
		if (order == 0 && species == 0) return 0;
		// round up to next integer. integer divide, add one if there was a remainder
		return order / species + ((order % species != 0) ? 1: 0);
	}
}
