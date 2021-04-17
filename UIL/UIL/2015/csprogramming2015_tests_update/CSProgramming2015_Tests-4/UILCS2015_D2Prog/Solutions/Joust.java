import java.util.*;
import java.io.*;

public class Joust {
	public static void main(String args[]) throws IOException {
		Scanner scan = new Scanner(new File("joust.dat"));

		int T = Integer.parseInt(scan.nextLine());

		for (int casenum = 1; casenum <= T; casenum++) {
			int N = Integer.parseInt(scan.nextLine());

			int[] skills = new int[N];
			String[] names = new String[N];

			for (int i = 0; i < N; i++) {
				String[] line = scan.nextLine().split(" ");
				names[i] = line[0];
				skills[i] = Integer.parseInt(line[1]);
			}
			int[] results = new int[N];
			for (int i = 0; i < N; i++) results[i] = i;
			while (results.length > 4) {
				int[] newresults = new int[results.length / 2];
				for (int i = 0; i < newresults.length; i++) {
					if (skills[results[2*i]] > skills[results[2*i+1]]) {
						newresults[i] = results[2*i];
					} else {
						newresults[i] = results[2*i+1];
					}
				}
				results = newresults;
			}
			int winner, second, third, semi1W, semi1L, semi2W, semi2L;
			if (skills[results[0]] > skills[results[1]]) {
				semi1W = results[0];
				semi1L = results[1];
			} else {
				semi1W = results[1];
				semi1L = results[0];
			}
			if (skills[results[2]] > skills[results[3]]) {
				semi2W = results[2];
				semi2L = results[3];
			} else {
				semi2W = results[3];
				semi2L = results[2];
			}
			if (skills[semi1W] > skills[semi2W]) {
				winner = semi1W;
				second = semi2W;
			} else {
				winner = semi2W;
				second = semi1W;
			}
			if (skills[semi1L] > skills[semi2L]) {
				third = semi1L;
			} else {
				third = semi2L;
			}
			System.out.printf("Case %d:\r\n", casenum);
			System.out.println("1: " + names[winner]);
			System.out.println("2: " + names[second]);
			System.out.println("3: " + names[third]);
		}

		scan.close();
	}
}
