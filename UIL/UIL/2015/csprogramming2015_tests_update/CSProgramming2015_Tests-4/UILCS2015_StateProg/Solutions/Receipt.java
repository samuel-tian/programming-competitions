import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Receipt {

    public static void main(String[] args) throws IOException {
        final Scanner scan = new Scanner(new File("receipt.dat"));
        final int T = scan.nextInt();
        for (int case_num = 1; case_num <= T; case_num++) {
            System.out.printf("Grocery Store #%d:\n", case_num);
            final String item1 = scan.next();
            final String item2 = scan.next();

            final int a = scan.nextInt();
            final int b = scan.nextInt();
            final double o1 = scan.nextDouble();
            final int c = scan.nextInt();
            final int d = scan.nextInt();
            final double o2 = scan.nextDouble();

            final long det = a * d - b * c;
            if (det == 0) {
                System.out.println("CANNOT COMPUTE PRICES");
            } else {
                final double scalar = 1.0 / det;
                final double ans1 = scalar * (d * o1 - b * o2);
                final double ans2 = scalar * (- c * o1 + a * o2);

                System.out.printf("%s: %.2f, %s: %.2f\n", item1, ans1, item2, ans2);
            }

        }
    }

}
