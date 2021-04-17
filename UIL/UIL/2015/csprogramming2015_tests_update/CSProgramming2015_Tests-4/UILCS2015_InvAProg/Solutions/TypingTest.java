import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class TypingTest {

    public static void main(String[] args) throws IOException {
        final Scanner scanner = new Scanner(new File("typingtest.dat"));
        int N = scanner.nextInt();
        scanner.nextLine();
        while (N-- > 0) {
            final String[] words = scanner.nextLine().split("\\s");
            int S = Integer.parseInt(words[0]);
            int wordCount = words.length - 1;
            System.out.println((int)Math.round(60.0 * wordCount / S) + " WPM");
        }
    }
}
