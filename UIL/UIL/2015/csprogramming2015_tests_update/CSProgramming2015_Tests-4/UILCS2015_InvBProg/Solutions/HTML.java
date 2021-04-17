import java.io.*;
import java.util.*;


public class HTML{
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("html.dat"));
    int numcases = Integer.parseInt(in.nextLine().trim());
    while (numcases-- > 0) {
      String pageA = in.nextLine().trim();
      String pageB = in.nextLine().trim();
      List<String> tagsA = getTags(pageA);
      List<String> tagsB = getTags(pageB);
      if (tagsA.equals(tagsB)) {
        System.out.println("same");
      } else {
        System.out.println("different");
      }
    }
  }

  static List<String> getTags(String html) {
    List<String> tags = new ArrayList<String>();
    getTags(html, 0, tags);
    return tags;
  }

  static void getTags(String html, int startIndex, List<String> tags) {
    int nextTagStart = html.indexOf("<", startIndex);
    if (nextTagStart == -1) {
      return;
    }
    int nextTagEnd = html.indexOf(">", nextTagStart) + 1;
    tags.add(html.substring(nextTagStart, nextTagEnd));
    getTags(html, nextTagEnd, tags);
  }

}
