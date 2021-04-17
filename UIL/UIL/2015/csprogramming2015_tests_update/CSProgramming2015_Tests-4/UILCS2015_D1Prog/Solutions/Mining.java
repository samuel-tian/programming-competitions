import java.util.Scanner;
import java.io.*;

public class Mining {
	public static void main(String args[]) throws IOException {
		Scanner scan = new Scanner(new File("mining.dat"));

		int T = Integer.parseInt(scan.nextLine());

		while (T-- > 0) {
			int N = scan.nextInt();
			int M = scan.nextInt();
			scan.nextLine();
			char[][] radar = new char[N][M];
			for (int i = 0; i < N; i++) {
				radar[i] = scan.nextLine().trim().toCharArray();
			}
			int startR = -1;
			int startC = -1;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (radar[i][j] == 'S') {
						startR = i;
						startC = j;
						break;
					}
				}
			}
			System.out.println(count(startR, startC, radar, new boolean[N][M]));
		}

		scan.close();
	}

	public static int[][] deltas = new int[][] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	// modified DFS to count crystals as it goes
	public static int count(int r, int c, char[][] radar, boolean[][] visited) {
		visited[r][c] = true;
		int total = 0;
		if (radar[r][c] == 'C') total++;
		for (int k = 0; k < 4; k++) {
			int newr = r + deltas[k][0];
			int newc = c + deltas[k][1];
			if (newr < 0 || newr >= radar.length || newc < 0 || newc >= radar[newr].length) continue;
			if (visited[newr][newc] || radar[newr][newc] == 'O') continue;
			total += count(newr, newc, radar, visited);
		}
		return total;
		
	}
}
