import java.util.*;
import java.io.*;

public class Railroad {
	public static void main(String args[]) throws IOException {
		Scanner in = new Scanner(new File("railroad.dat"));

		int T = in.nextInt();

		for (int casenum = 1; casenum <= T; casenum++) {

			int N = in.nextInt();
			int M = in.nextInt();
			int K = in.nextInt();

			boolean[] rows = new boolean[N];
			boolean[] cols = new boolean[M];
			Arrays.fill(rows, true);
			Arrays.fill(cols, true);

			while (K-- > 0) {
				int R = in.nextInt();
				int C = in.nextInt();
				int W = in.nextInt();
				int H = in.nextInt();
				for (int i = 0; i < W; i++) {
					rows[R+i] = false;	
				}
				for (int i = 0; i < H; i++) {
					cols[C+i] = false;
				}
			}

			int total = 0;
			for (int i = 0; i < N; i++) {
				if (rows[i]) total++;	
			}
			for (int i = 0; i < M; i++) {
				if (cols[i]) total++;	
			}
			System.out.println(total);
		}

		in.close();
	}
}
