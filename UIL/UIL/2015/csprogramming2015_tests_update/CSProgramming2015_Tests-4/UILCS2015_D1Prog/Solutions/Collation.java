import java.io.*;
import java.util.*;

public class Collation {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(new File("collation.dat"));
    int numTests = in.nextInt();
    in.nextLine();
    for (int z = 0; z < numTests; ++z) {
      final String order = in.nextLine();
      int numWords = in.nextInt();
      in.nextLine();
      String[] words = in.nextLine().split(" ");
      Arrays.sort(words, new Comparator<String>() {
        @Override
        public int compare(String o1, String o2) {
          if (o1.length() == 0 && o2.length() != 0)
            return -1;
          else if (o1.length() != 0 && o2.length() == 0)
            return 1;
          else if (0 == o2.length() && o1.length() == 0)
            return 0;
          else
            return o1.charAt(0) != o2.charAt(0)
              ? order.indexOf(o1.charAt(0)) - order.indexOf(o2.charAt(0))
              : compare(o1.substring(1), o2.substring(1));
        }
      });
      String delim = "";
      for (int i = 0; i < words.length; ++i) {
        System.out.print(delim + words[i]);
        delim = " ";
      }
      System.out.println();
    }
  }
}
