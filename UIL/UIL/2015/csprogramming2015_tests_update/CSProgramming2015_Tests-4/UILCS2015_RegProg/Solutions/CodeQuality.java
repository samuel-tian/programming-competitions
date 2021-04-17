import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.Stack;

public class CodeQuality {
    public enum SymbolType {
        PAREN, SQUARE, CURLY, ANY
    }

    public static void main(String[] args) throws IOException {
        final Scanner scan = new Scanner(new File("codequality.dat"));
        final int T = scan.nextInt();
        scan.nextLine();

        for (int case_num = 0; case_num < T; case_num++) {
            final int N = scan.nextInt();
            final Stack<SymbolType> symbolStack = new Stack<>();
            int paren = 0;
            int square = 0;
            int curly = 0;
            int totalParen = 0;
            int totalSquare = 0;
            int totalCurly = 0;

            int offset = 0;
            int invalidIndex = -1;
            boolean valid = true;

            scan.nextLine();

            for (int line_num = 0; line_num < N; line_num++) {
                final String line = scan.nextLine();
                for (int i = 0; i < line.length(); i++) {
                    if (!valid) {
                        break;
                    }
                    switch (line.charAt(i)) {
                        case '(':
                            paren++;
                            totalParen++;
                            symbolStack.push(SymbolType.PAREN);
                            break;
                        case '[':
                            square++;
                            totalSquare++;
                            symbolStack.push(SymbolType.SQUARE);
                            break;
                        case '{':
                            curly++;
                            totalCurly++;
                            symbolStack.push(SymbolType.CURLY);
                            break;
                        case ')':
                            boolean cv = (!symbolStack.empty() &&
                                    (symbolStack.peek() == SymbolType.PAREN || symbolStack.peek() == SymbolType.ANY))
                                    && paren > 0;
                            if (!cv) {
                                valid = false;
                                invalidIndex = offset + i;
                                break;
                            }
                            paren--;
                            totalParen++;
                            symbolStack.pop();
                            break;
                        case ']':
                            boolean cv1 = (!symbolStack.empty() &&
                                    (symbolStack.peek() == SymbolType.SQUARE || symbolStack.peek() == SymbolType.ANY))
                                    && square > 0;
                            if (!cv1) {
                                valid = false;
                                invalidIndex = offset + i;
                                break;
                            }
                            square--;
                            totalSquare++;
                            symbolStack.pop();
                            break;
                        case '}':
                            boolean cv2 = (!symbolStack.empty() &&
                                    (symbolStack.peek() == SymbolType.CURLY || symbolStack.peek() == SymbolType.ANY))
                                    && curly > 0;
                            if (!cv2) {
                                valid = false;
                                invalidIndex = offset + i;
                                break;
                            }
                            curly--;
                            totalCurly++;
                            symbolStack.pop();
                            break;
                    }
                }

                offset += line.length();
            }
            valid &= paren == 0 && square == 0 && curly == 0;
            if (valid) {
                System.out.printf("YES %d () %d [] %d {}\r\n", totalParen, totalSquare, totalCurly);
            } else {
                System.out.printf("NO %d\r\n", invalidIndex);
            }
        }
    }
}
