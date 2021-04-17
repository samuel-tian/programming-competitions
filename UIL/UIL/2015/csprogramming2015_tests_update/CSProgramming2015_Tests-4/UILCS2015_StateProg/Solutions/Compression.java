import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Compression {

    public static void main(String[] args) throws IOException {
        final Scanner s = new Scanner(new File("compression.dat"));

        final int T = s.nextInt();
        s.nextLine();
        for (int case_num = 0; case_num < T; case_num++) {
            final String text = s.nextLine();
            final StringBuilder stringBuilder = new StringBuilder();

            int p = 0;
            while (p < text.length()) {
                char c = text.charAt(p);
                p++;
                int count = 1;
                while(p < text.length() && text.charAt(p) == c) {
                    p++;
                    count++;
                }

                stringBuilder.append(count);
                stringBuilder.append(c);
            }

            System.out.println(stringBuilder.toString());
        }
    }
}
