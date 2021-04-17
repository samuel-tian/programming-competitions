import java.io.*;
import java.util.*;

public class Scoreboard {
  public static void main(String[] args) throws IOException {
    String delim = "";
    Scanner in = new Scanner(new File("scoreboard.dat"));
    int numTests = in.nextInt();
    in.nextLine();
    for (int z = 0; z < numTests; ++z) {
      int[][] accum = new int[25][12];
      final int[] scores = new int[25];
      Set<Integer> submitted = new HashSet<Integer>();

      in.nextLine();
      int numEntries = in.nextInt();
      in.nextLine();
      for (int e = 0; e < numEntries; ++e) {
        String[] data = in.nextLine().split(" ");
        int team = Integer.parseInt(data[0]) - 1;
        int prob = Integer.parseInt(data[1]) - 1;
        switch (data[2]) {
          case "A":
            submitted.add(team);
            scores[team] += Math.max(60 - accum[team][prob] * 5, 0);
            accum[team][prob] = -1;
            break;
          case "I":
            submitted.add(team);
            accum[team][prob] += 1;
            break;
          case "U":
          case "E":
            submitted.add(team);
            break;
        }
      }
      ArrayList<Integer> scoreboard = new ArrayList<Integer>(submitted);
      Collections.sort(scoreboard, new Comparator<Integer>() {
        @Override
        public int compare(Integer o1, Integer o2) {
          if (scores[o1] != scores[o2])
            return scores[o2] - scores[o1];
          return o1 - o2;
        }
      });

      System.out.print(delim);
      delim = "\n";
      for (int team : scoreboard) {
        int solved = 0;
        for (int a : accum[team])
          solved += a == -1 ? 1 : 0;
        System.out.printf("%d %d %d\n", team + 1, solved, scores[team]);
      }
    }
  }
}
