import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class GeneralFib {

    public static int f(int x, int y, int a, int b, int n) {
        if (n == 1) {
            return x;
        } else if (n == 2) {
            return y;
        } else {
            int v1 = x;
            int v2 = y;
            for (int i = 3; i <= n; i++) {
                final int t = v2;
                v2 = b * v1 + a * v2;
                v1 = t;
            }
            return v2;
        }
    }

    public static void main(String[] args) throws IOException {
        final Scanner s = new Scanner(new File("generalfib.dat"));
        final int T = s.nextInt();
        for (int i = 0; i < T; i++) {
            final int x = s.nextInt();
            final int y = s.nextInt();
            final int a = s.nextInt();
            final int b = s.nextInt();
            final int n = s.nextInt();
            System.out.println(f(x, y, a, b, n));
        }
    }
}
