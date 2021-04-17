import java.io.*;
import java.util.*;

public class Resources {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(new File("resources.dat"));
    int testCases = in.nextInt();
    for (int zz = 0; zz < testCases; ++zz) {
      int availMem = in.nextInt();
      int numJobs = in.nextInt();
      TreeMap<Integer, Integer> changes = new TreeMap<Integer, Integer>();
      for (int i = 0; i < numJobs; ++i) {
        int usage = in.nextInt();
        int startTime = in.nextInt();
        int endTime = startTime + in.nextInt();
        if (!changes.containsKey(startTime))
          changes.put(startTime, 0);
        if (!changes.containsKey(endTime))
          changes.put(endTime, 0);
        changes.put(startTime, changes.get(startTime) + usage);
        changes.put(endTime, changes.get(endTime) - usage);
      }

      int maxUsed = 0;
      int currUsed = 0;
      for (Map.Entry<Integer, Integer> entry : changes.entrySet()) {
        currUsed += entry.getValue();
        maxUsed = maxUsed < currUsed ? currUsed : maxUsed;
      }

      if (maxUsed > availMem) {
        System.out.printf("OUT OF MEMORY: %dKB REQUESTED\n", maxUsed);
      } else {
        System.out.printf("SUFFICIENT\n");
      }
    }
  }
}
