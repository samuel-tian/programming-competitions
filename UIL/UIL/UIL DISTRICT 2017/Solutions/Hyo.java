import java.util.PriorityQueue;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.TreeMap;
import java.util.HashMap;

public class Hyo {
  public static void main(String [] args) throws FileNotFoundException {
    Scanner f = new Scanner(new File("hyo.dat"));
    int N = f.nextInt();f.nextLine();
    while(N-- > 0) {
      TreeMap<String, Vertex> peeps = new TreeMap<>();
      HashMap<String, String> friendOutput = new HashMap<>();
      int numFriends = f.nextInt();f.nextLine();
      while(numFriends-- > 0) {
        String line = f.nextLine();
        Scanner chop = new Scanner(line);
        String personName = chop.next();
        personName = personName.substring(0, personName.length()-1);
        Vertex person = new Vertex(personName);
        peeps.put(personName, person);
        friendOutput.put(personName, line.substring(line.indexOf(':')+1));
      }
      for(String name : friendOutput.keySet()) {
        Scanner chop = new Scanner(friendOutput.get(name));
        ArrayList<Edge> friendsList = new ArrayList<>();
        while(chop.hasNext()) {
          friendsList.add(new Edge(peeps.get(chop.next()), 1));
        }
        Edge[] friends = friendsList.toArray(new Edge[friendsList.size()]);
        peeps.get(name).adjacencies = friends;
      }
      String finds = f.nextLine();
      String start = finds.split(" ")[0];
      computePaths(peeps.get(start));
      String friend = finds.split(" ")[1];
      System.out.println("The degree of separation between " + start + " and " + friend + " is " + (int)(peeps.get(friend).minDistance) + ".");
      List<Vertex> path = getShortestPathTo(peeps.get(friend));
      String out = start;
      for(Vertex v: path) {
        if(v.name.equals(start)) {
          continue;
        }
        out += " is a friend of " + v.name;
      }
      System.out.println(out + ".");
    }
  }

  public static void computePaths(Vertex source) {
      source.minDistance = 0.;
      PriorityQueue<Vertex> vertexQueue = new PriorityQueue<Vertex>();
      vertexQueue.add(source);

      while (!vertexQueue.isEmpty()) {
          Vertex u = vertexQueue.poll();
          // Visit each edge exiting u
          for (Edge e : u.adjacencies) {
              Vertex v = e.target;
              double weight = e.weight;
              double distanceThroughU = u.minDistance + weight;
              if (distanceThroughU < v.minDistance) {
                  vertexQueue.remove(v);

                  v.minDistance = distanceThroughU ;
                  v.previous = u;
                  vertexQueue.add(v);
              }
          }
      }
  }

  public static List<Vertex> getShortestPathTo(Vertex target) {
    List<Vertex> path = new ArrayList<Vertex>();
    for (Vertex vertex = target; vertex != null; vertex = vertex.previous)
        path.add(vertex);

    Collections.reverse(path);
    return path;
  }
}

class Vertex implements Comparable<Vertex> {
  public final String name;
  public Edge[] adjacencies;
  public double minDistance = Double.POSITIVE_INFINITY;
  public Vertex previous;
  public Vertex(String argName) { name = argName; }
  public String toString() { return name; }
  public int compareTo(Vertex other) {
      return Double.compare(minDistance, other.minDistance);
  }
}

class Edge {
  public final Vertex target;
  public final double weight;
  public Edge(Vertex argTarget, double argWeight) {
    target = argTarget; weight = argWeight; }
}
