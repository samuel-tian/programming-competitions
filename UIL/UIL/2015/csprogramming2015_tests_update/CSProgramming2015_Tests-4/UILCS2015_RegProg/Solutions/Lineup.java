import java.io.*;
import java.util.*;

public class Lineup {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("lineup.dat"));
		int T = in.nextInt();
		for (int casenum = 1; casenum <= T; casenum++) {
			int N = in.nextInt();
			Soldier[] soldiers = new Soldier[N];
			for (int i = 0; i < N; i++) {
				String F = in.next();
				String L = in.next();
				int H = in.nextInt();
				soldiers[i] = new Soldier(F, L, H);
			}
			Arrays.sort(soldiers);
			System.out.printf("Test Case #%d:\n", casenum);
			for (int i = 0; i < N; i++) {
				System.out.println(soldiers[i].first + " " + soldiers[i].last);
			}
		}
	}

	static class Soldier implements Comparable<Soldier> {
		String first, last;
		int height;
		Soldier(String F, String L, int H) {
			this.first = F;
			this.last = L;
			this.height = H;
		}
		public int compareTo(Soldier other) {
			if (this.height == other.height) {
				if (this.last.equals(other.last)) {
					return this.first.compareTo(other.first);
				} else {
					return this.last.compareTo(other.last);
				}
			} else {
				return this.height - other.height;
			}
		}
	}
}
