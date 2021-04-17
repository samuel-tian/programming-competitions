import java.io.FileNotFoundException;
import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

class Jean {
  public static void main(String [] args) throws FileNotFoundException{
    Scanner f = new Scanner(new File("jean.dat"));
    int N = f.nextInt(); f.nextLine();
    while(N-- > 0) {
      TreeMap<String, String[]> graph = new TreeMap<>();
      int n = f.nextInt();f.nextLine();
      while(n-- > 0) {
        String line = f.nextLine();
        String[] toFrom = line.split(" -> ");
        String[] to = toFrom[1].split(" ");
        // System.out.println(toFrom[0] + " " + toFrom[1]);
        if(to[0].equals("NONE")) {
          to = new String[0];
        }
        graph.put(toFrom[0], to);
      }
      // DEBUG PRINT
      // for(String key: graph.keySet()) {
      //   System.out.print(key + " -> ");
      //   for(String e: graph.get(key)) {
      //     System.out.print(e + " ");
      //   }
      //   System.out.println();
      // }
      String sources = "";
      String sinks = "";
      for(String key: graph.keySet()) {
        if(graph.get(key).length == 0 && numPointingTo(graph, key) > 0) {
          sinks += key + " ";
        }

        if(graph.get(key).length > 0 && numPointingTo(graph, key) == 0) {
          sources += key + " ";
        }
      }
      if(sources.length() == 0) {
        sources = "NONE";
      }
      if(sinks.length() == 0) {
        sinks = "NONE";
      }

      System.out.println("Sources: " + sources);
      System.out.println("Sinks: " + sinks);
    }
  }

  public static int numPointingTo(TreeMap<String, String[]> graph, String node) {
    int count = 0;
    for(String key: graph.keySet()) {
      for(String e: graph.get(key)) {
        if(e.equals(node)) {
            count++;
        }
      }
    }
    return count;
  }
}
