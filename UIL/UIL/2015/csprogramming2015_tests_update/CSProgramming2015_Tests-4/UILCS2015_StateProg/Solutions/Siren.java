import java.io.*;
import java.util.*;

public class Siren {
	static int N;
	static boolean[] end;
	static boolean[][] adjMat;
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("siren.dat"));
		int T = in.nextInt();
		while (T-- > 0) {
			N = in.nextInt();
			int W = in.nextInt();
			Island[] sirens = new Island[N];
			end = new boolean[N];
			ArrayList<Integer> start = new ArrayList<Integer>();
			for (int i = 0; i < N; i++) {
				sirens[i] = new Island(in.nextInt(), in.nextInt(), in.nextInt());
				if (W-sirens[i].y <= sirens[i].r) {
					end[i] = true;
				}
				if (sirens[i].r >= sirens[i].y) {
					start.add(i);
				}
			}
			adjMat = new boolean[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < i; j++) {
					if (sirens[i].overlap(sirens[j])) {
						adjMat[i][j] = true;
						adjMat[j][i] = true;
					}
				}
			}
			boolean good = false;
			for (Integer i: start) {
				if (reachable(i, new boolean[N])) {
					good = true;
					break;
				}
			}
			System.out.println(good?"NO":"YES");
		}
	}
	static class Island {
		int x, y, r;
		public Island(int X, int Y, int R) {
			this.x = X;
			this.y = Y;
			this.r = R;
		}
		public boolean overlap(Island other) {
			int dx = other.x - this.x;
			int dy = other.y - this.y;
			int distSquared = dx*dx+dy*dy;
			int radSquared = (this.r + other.r) * (this.r+other.r);
			return radSquared >= distSquared;
		}
	}
	static boolean reachable(int cur, boolean[] visited) {
		if (end[cur]) return true;
		visited[cur] = true;
		for (int i = 0; i < N; i++) {
			if (adjMat[cur][i] && !visited[i] && reachable(i, visited)) {
				return true;
			} 
		}
		return false;
	}
}