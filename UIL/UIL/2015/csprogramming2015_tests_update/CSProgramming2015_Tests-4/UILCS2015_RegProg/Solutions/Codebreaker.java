import java.io.*;
import java.util.*;

public class Codebreaker {

  public static boolean valid(String phrase, char[] decode, HashMap<Integer, HashSet<String>> dict) {
    StringBuilder sb = new StringBuilder();
    for (char c : phrase.toCharArray()) {
      if (decode[c - 'a'] == 0)
        return false;
      sb.append(decode[c - 'a']);
    }
    return dict.containsKey(sb.length()) && dict.get(sb.length()).contains(sb.toString());
  }

  public static boolean recurse(String[] phrases, int idx, char[] decode, HashMap<Integer, HashSet<String>> dict) {
    if (idx == phrases.length)
      return true;
    if (!dict.containsKey(phrases[idx].length()))
      return false;
    if (valid(phrases[idx], decode, dict))
      return recurse(phrases, idx + 1, decode, dict);
    for (String word : dict.get(phrases[idx].length())) {
      boolean success = true;
      for (int i = 0; i < word.length(); ++i) {
        char c = phrases[idx].charAt(i);
        char d = word.charAt(i);
        if (decode[c - 'a'] != 0 && decode[c - 'a'] != d)
          success = false;
      }
      if (success) {
        char[] copy = Arrays.copyOf(decode, decode.length);
        for (int i = 0; i < word.length(); ++i)
          copy[phrases[idx].charAt(i) - 'a'] = word.charAt(i);
        if (recurse(phrases, idx + 1, copy, dict)) {
          for (int i = 0; i < copy.length; ++i)
            decode[i] = copy[i];
          return true;
        }
      }
    }
    return false;
  }

  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(new File("codebreaker.dat"));
    int n = in.nextInt();
    int m = in.nextInt();
    in.nextLine();
    HashMap<Integer, HashSet<String>> dict = new HashMap<Integer, HashSet<String>>();
    for (int i = 0; i < n; ++i) {
      String word = in.nextLine().trim();
      if (!dict.containsKey(word.length()))
        dict.put(word.length(), new HashSet<String>());
      dict.get(word.length()).add(word);
    }

    for (int i = 0; i < m; ++i) {
      String[] phrases = in.nextLine().split(" ");
      char[] decode = new char[26];
      boolean success = recurse(phrases, 0, decode, dict);
      if (success) {
        StringBuilder sb = new StringBuilder();
        String delim = "";
        for (String phrase : phrases) {
          sb.append(delim);
          delim = " ";
          for (char c : phrase.toCharArray()) {
            sb.append(decode[c - 'a']);
          }
        }
        System.out.println(sb.toString());
      } else {
        System.out.println("Unable to decrypt message.");
      }
    }
  }
}
