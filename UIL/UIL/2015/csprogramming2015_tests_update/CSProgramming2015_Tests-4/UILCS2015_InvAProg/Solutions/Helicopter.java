import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Helicopter {

    public static void main(String[] args) throws IOException {
        final Scanner scanner = new Scanner(new File("helicopter.dat"));
        int N = scanner.nextInt();
        while (N-- > 0) {
            final int W = scanner.nextInt();
            final int L = scanner.nextInt();
            final int[][] buildings = new int[L][W];

            for (int i = 0; i < L; i++) {
                for (int j = 0; j < W; j++) {
                    buildings[i][j] = scanner.nextInt();
                }
            }

            int bestR = 0, bestC = 0, bestW = 1, bestL = 1, buildingHeight = buildings[0][0];
            for (int r = 0; r < L; r++) {
                for (int c = 0; c < W; c++) {
                    for (int w = 1; r + w <= L; w++) {
                        for (int l = 1; c + l <= W; l++) {
                            if (w*l >= bestW * bestL && validRectangle(buildings, r, c, w, l)) {
                                if (w*l > bestW * bestL || (w*l == bestW * bestL && buildings[r][c] > buildingHeight)) {
                                    bestR = r;
                                    bestC = c;
                                    bestW = w;
                                    bestL = l;
                                    buildingHeight = buildings[r][c];
                                }
                            }
                        }
                    }
                }
            }

            System.out.printf("Area: %d square blocks\n", bestW * bestL);
            System.out.printf("Start location: %d %d\n", bestR, bestC);
            System.out.printf("Width: %d\n", bestW);
            System.out.printf("Height: %d\n", bestL);
            if (N > 0) {
                System.out.println();
            }
        }
    }

    private static boolean validRectangle(int[][] buildings, int r, int c, int w, int l) {
        final int expectedHeight = buildings[r][c];
        for (int i = r; i < r + w; i++) {
            for (int j = c; j < c + l; j++) {
                if (buildings[i][j] != expectedHeight) {
                    return false;
                }
            }
        }

        return true;
    }
}
