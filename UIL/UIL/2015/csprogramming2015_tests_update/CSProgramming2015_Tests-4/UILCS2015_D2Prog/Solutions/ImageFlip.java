import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class ImageFlip {

    public static void main(String[] args) throws IOException {
        final Scanner scanner = new Scanner(new File("imageflip.dat"));
        final int T = scanner.nextInt();
        for (int case_number = 0; case_number < T; case_number++) {
            final int N = scanner.nextInt();
            final int M = scanner.nextInt();
            final char type = scanner.next().charAt(0);

            final char[][] picture = new char[N][M];
            for (int i = 0; i < N; i++) {
                picture[i] = scanner.next().toCharArray();
            }
            if (type == 'H') {
                flipHorizontal(picture);
            } else {
                flipVertical(picture);
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    System.out.print(picture[i][j]);
                }
                System.out.println();
            }

            if (case_number < T - 1) {
                System.out.println();
            }
        }
    }

    private static void flipHorizontal(char[][] picture) {
        for (int i = 0; i < picture.length; i++) {
            int start = 0;
            int end = picture[i].length - 1;
            while (start < end) {
                final char temp = picture[i][start];
                picture[i][start] = picture[i][end];
                picture[i][end] = temp;

                start++;
                end--;
            }
        }
    }

    private static void flipVertical(char[][] picture) {
        for (int i = 0; i < picture[0].length; i++) {
            int start = 0;
            int end = picture.length - 1;
            while (start < end) {
                final char temp = picture[start][i];
                picture[start][i] = picture[end][i];
                picture[end][i] = temp;

                start++;
                end--;
            }
        }
    }
}
