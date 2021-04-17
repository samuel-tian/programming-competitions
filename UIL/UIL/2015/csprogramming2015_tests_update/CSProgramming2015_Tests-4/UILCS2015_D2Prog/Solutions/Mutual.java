import java.util.*;
import java.io.*;

public class Mutual {
	public static void main(String args[]) throws IOException {
		Scanner scan = new Scanner(new File("mutual.dat"));

		int T = Integer.parseInt(scan.nextLine());

		for (int casenum = 1; casenum <= T; casenum++) {
			List<String> results = new ArrayList<String>();
			int N = Integer.parseInt(scan.nextLine());
			List<String> first = new ArrayList<String>();
			for (int i = 0; i < N; i++) {
				first.add(scan.nextLine());
			}
			int M = Integer.parseInt(scan.nextLine());
			for (int i = 0; i < M; i++) {
				String name = scan.nextLine();
				if (first.contains(name)) {
					results.add(name);
				}
			}

			Collections.sort(results);

			System.out.printf("Case %d:\r\n", casenum);
			for (String name : results) {
				System.out.println(name);
			}
		}

		scan.close();
	}
}
