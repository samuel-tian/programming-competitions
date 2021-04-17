import java.io.*;
import java.util.*;

public class Pattern {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(new File("pattern.dat"));
    int numTests = in.nextInt();
    in.nextLine();
    for (int z = 0; z < numTests; ++z) {
      String pattern = in.nextLine();
      String[] words = in.nextLine().split(" ");
      if (pattern.length() != words.length) {
        System.out.println("Does Not Match");
        continue;
      }

      HashMap<Character, String> c2w = new HashMap<Character, String>();
      HashMap<String, Character> w2c = new HashMap<String, Character>();
      boolean success = true;
      for (int i = 0; i < words.length; ++i) {
        char c = pattern.charAt(i);
        String w = words[i];
        if (c2w.containsKey(c) && !c2w.get(c).equals(w)) {
          success = false;
          break;
        } else if (w2c.containsKey(w) && w2c.get(w) != c) {
          success = false;
          break;
        }
        c2w.put(c, w);
        w2c.put(w, c);
      }
      if (success) {
        System.out.println("Matches");
      } else {
        System.out.println("Does Not Match");
      }
    }
  }
}
