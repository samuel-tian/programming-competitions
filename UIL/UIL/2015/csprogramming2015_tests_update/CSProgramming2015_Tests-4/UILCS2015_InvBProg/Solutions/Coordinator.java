import java.io.*;
import java.util.*;

public class Coordinator {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(new File("coordinator.dat"));
    int testCases = in.nextInt();
    for (int zz = 0; zz < testCases; ++zz) {
      int numRooms = in.nextInt();
      int numEvents = in.nextInt();

      int[] roomCapacities = new int[numRooms];
      for (int i = 0; i < numRooms; ++i) {
        roomCapacities[i] = in.nextInt();
      }

      TreeMap<Integer, Integer> changes = new TreeMap<Integer, Integer>();
      for (int i = 0; i < numEvents; ++i) {
        int startTime = in.nextInt();
        int endTime = in.nextInt();
        int size = in.nextInt();
        if (!changes.containsKey(startTime))
          changes.put(startTime, 0);
        if (!changes.containsKey(endTime))
          changes.put(endTime, 0);
        changes.put(startTime, changes.get(startTime) + size);
        changes.put(endTime, changes.get(endTime) - size);
      }

      int maxUsed = 0;
      int currUsed = 0;
      for (Map.Entry<Integer, Integer> entry : changes.entrySet()) {
        currUsed += entry.getValue();
        maxUsed = maxUsed < currUsed ? currUsed : maxUsed;
      }

      int smallestRoomIdx = -1;
      for (int i = 0; i < numRooms; ++i) {
        if (roomCapacities[i] >= maxUsed
            && (smallestRoomIdx == -1 || roomCapacities[i] < roomCapacities[smallestRoomIdx]))
          smallestRoomIdx = i;
      }
      System.out.println(smallestRoomIdx != -1 ? (char) ('A' + smallestRoomIdx) : "Not Possible");
    }
  }
}
