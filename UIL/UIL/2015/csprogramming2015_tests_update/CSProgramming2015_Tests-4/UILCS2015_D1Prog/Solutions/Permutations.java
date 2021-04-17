import java.io.*;
import java.util.*;

public class Permutations {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(new File("permutations.dat"));
    int num = in.nextInt();
    in.nextLine();
    for (int i = 0; i < num; ++i) {
      String word = in.nextLine();
      int ways = 1;
      for (int k = 2; k <= word.length(); ++k)
        ways *= k;
      int[] chars = new int[26];
      for (char c : word.toCharArray())
        chars[c - 'a']++;
      for (int k = 0; k < 26; ++k) {
        if (chars[k] > 1) {
          int temp = 2;
          for (int x = 3; x <= chars[k]; ++x)
            temp *= x;
          ways /= temp;
        }
      }
      System.out.println(ways);
    }
  }
}
