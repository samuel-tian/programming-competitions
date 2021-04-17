import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashSet;

public class Denise {
  public static void main(String [] args) throws FileNotFoundException {
    Scanner f = new Scanner(new File("denise.dat"));
    int N = f.nextInt(); f.nextLine();
    while(N-- > 0) {
      GridPoint [][] grid = new GridPoint[10][10];
      ArrayList<GridPoint> items = new ArrayList<>();
      for(int i = 0 ; i < 10; i++) {
        String line = f.nextLine();
        for(int j = 0; j < 10; j++) {
          boolean isStart = (line.charAt(j)!='#' && (i==9 || j==9 || i==0 || j==0));
          boolean isItem = line.charAt(j) == 'o';
          grid[i][j] = new GridPoint(line.charAt(j), 1000, isStart, isItem);
          grid[i][j].i = i;
          grid[i][j].j = j;
          if(isItem) {
            items.add(grid[i][j]);
          }
        }
      }
      f.nextLine();
      int count = 1000;
      while(!allItemsFound(items) || count > 0) {
        count --;
        for(int i = 0; i < 10; i ++) {
          for(int j = 0; j < 10; j ++) {
            GridPoint cur = grid[i][j];
            if(cur.spot == '#') {
              continue;
            }
            GridPoint up = i > 0 ? grid[i-1][j] : null;
            GridPoint down = i < 9 ? grid[i+1][j] : null;
            GridPoint left = j > 0 ? grid[i][j-1] : null;
            GridPoint right = j < 9 ? grid[i][j+1] : null;
            GridPoint [] neighbors = {up,down,left,right};
            for(GridPoint neighbor : neighbors) {
              if(neighbor == null){
                continue;
              }
              if(neighbor.spot =='#') {
                continue;
              }
              if(neighbor.distance > cur.distance) {
                  neighbor.distance = cur.distance + 1;
              }
            }
          }
        }
      }

      calcPaths(grid, items);
      System.out.println(countPaths(items));
    }
  }
  public static int countPaths(ArrayList<GridPoint> items) {
    int count = 0;
    HashSet<GridPoint> grabbed = new HashSet<>();
    while(grabbed.size() < items.size()) {
      int maxItems = 0;
      ArrayList<GridPoint> maxPath = null;

      for(GridPoint itemPath: items) {
        int lengthUnique = 0;
        for(GridPoint item: itemPath.itemsInPath) {
          if(!grabbed.contains(item)) {
            lengthUnique ++;
          }
          if(lengthUnique > maxItems) {
            maxItems = lengthUnique;
            maxPath = itemPath.itemsInPath;
          }
        }
      }

      count ++;
      for(GridPoint item: maxPath) {
        grabbed.add(item);
      }
    }
    return count;
  }

  public static void calcPaths(GridPoint [][] grid, ArrayList<GridPoint> items) {
    for(GridPoint item: items) {
      GridPoint cur = item;
      ArrayList<GridPoint> itemsInPath = new ArrayList<>();
      cur.itemsInPath = itemsInPath;
      itemsInPath.add(cur);
      while(cur.distance > 1) {
        GridPoint up = cur.i > 0 ? grid[cur.i-1][cur.j] : null;
        GridPoint down = cur.i < 9 ? grid[cur.i+1][cur.j] : null;
        GridPoint left = cur.j > 0 ? grid[cur.i][cur.j-1] : null;
        GridPoint right = cur.j < 9 ? grid[cur.i][cur.j+1] : null;
        GridPoint [] neighbors = {up,down,left,right};
        ArrayList<GridPoint> neighboringItems = new ArrayList<>();
        ArrayList<GridPoint> nextSteps = new ArrayList<>();
        for(GridPoint neighbor : neighbors) {
          if(neighbor == null){
            continue;
          }
          if(neighbor.distance != cur.distance - 1) {
            continue;
          }
          nextSteps.add(neighbor);
          if(neighbor.spot == 'o') {
            neighboringItems.add(neighbor);
          }
        }
        if(neighboringItems.size() == 0) {
          cur = nextSteps.get(0);
        } else {
          cur = neighboringItems.get(0);
          itemsInPath.add(cur);
        }
      }
    }
  }

  public static boolean allItemsFound(ArrayList<GridPoint> items) {
    for(GridPoint g: items) {
      if(g.distance >= 1000) {
        return false;
      }
    }
    return true;
  }
}
class GridPoint {
  public char spot;
  public int distance;
  public boolean isStart;
  public boolean isItem;
  public int i;
  public int j;
  public ArrayList<GridPoint> itemsInPath = null;
  public GridPoint(char spot, int distance, boolean isStart, boolean isItem) {
    this.spot = spot;
    this.distance = isStart ? 1: distance;
    this.isStart = isStart;
    this.isItem = isItem;
  }
  public String toString() {
    return String.format("(" + spot + "- dist: %04d" + /*+ " start: " + isStart + " end: " + isItem + */")", distance);
  }
}
