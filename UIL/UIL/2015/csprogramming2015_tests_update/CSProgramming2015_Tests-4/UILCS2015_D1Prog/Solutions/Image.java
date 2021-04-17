import java.util.*;
import java.io.*;

public class Image {
	public static void main(String args[]) throws IOException {
		Scanner scan = new Scanner(new File("image.dat"));
		int T = scan.nextInt();
		scan.nextLine();
		for(int a = 0; a < T; a++) //num cases
		{
		
			int N = scan.nextInt();
			int W = scan.nextInt();
			int H = scan.nextInt();
			scan.nextLine();
			String[] origNames = new String[N];
			int[][][] orig = new int[N][H][W];
			for (int i = 0; i < N; i++) {
				origNames[i] = scan.nextLine().trim();
				for (int y = 0; y < H; y++) {
					for (int x = 0; x < W; x++) {
						orig[i][y][x] = Integer.parseInt(scan.next(), 16);
					}
				}
				scan.nextLine();
			}
	
			String[] cloudNames = new String[N];
			int[][][] cloud = new int[N][H][W];
	
			for (int i = 0; i < N; i++) {
				cloudNames[i] = scan.nextLine().trim();
				for (int y = 0; y < H; y++) {
					for (int x = 0; x < W; x++) {
						cloud[i][y][x] = Integer.parseInt(scan.next(), 16);
					}
				}
				if(i!=N-1)
					scan.nextLine();
			}
			
	
			for (int i = 0; i < N; i++) {
				// find best for i
				int best = -1;
				int bestScore = Integer.MAX_VALUE;
				for (int j = 0; j < N; j++) {
					int score = 0;
					for (int y = 0; y < H; y++) {
						for (int x = 0; x < W; x++) {
							for (int k = 0; k < 3; k++) {
								int mask = 0xFF << k*8;
								score += Math.abs((mask & orig[i][y][x]) - (mask & cloud[j][y][x])) >> (k*8);
							}
						}
					}
					if (score < bestScore) {
						bestScore = score;
						best = j;
					} else if (score == bestScore) {
						System.out.println("ties should never happen......");
					}
				}
				System.out.println(origNames[i] + ": " + cloudNames[best]);
			}
			System.out.println();
		}			
			
		scan.close();
	}
}
