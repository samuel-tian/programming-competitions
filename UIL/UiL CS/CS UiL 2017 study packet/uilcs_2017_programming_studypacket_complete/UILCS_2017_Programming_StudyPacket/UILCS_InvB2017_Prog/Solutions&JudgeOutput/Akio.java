import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Akio {
  public static void main(String [] args) throws FileNotFoundException {
    Scanner f = new Scanner(new File("akio.dat"));
    int N = f.nextInt(); f.nextLine();
    while(N-- > 0) {
      Grid [][] grid = new Grid[10][10];
      Grid end = null;
      for(int i = 0 ; i < 10; i++) {
        String line = f.nextLine();
        for(int j = 0; j < 10; j++) {
          boolean isStart = (line.charAt(j)!='#' && (i==9 || j==9 || i==0 || j==0));
          boolean isEnd = line.charAt(j) == 'o';
          grid[i][j] = new Grid(line.charAt(j), 1000, isStart, isEnd);

          if(isEnd) {
            end = grid[i][j];
          }
        }
      }
      f.nextLine();
      while(end.distance >= 1000) {
        for(int i = 0; i < 10; i ++) {
          for(int j = 0; j < 10; j ++) {
            Grid cur = grid[i][j];
            if(cur.spot == '#') {
              continue;
            }
            Grid up = i > 0 ? grid[i-1][j] : null;
            Grid down = i < 9 ? grid[i+1][j] : null;
            Grid left = j > 0 ? grid[i][j-1] : null;
            Grid right = j < 9 ? grid[i][j+1] : null;
            Grid [] neighbors = {up,down,left,right};
            for(Grid neighbor : neighbors) {
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
      System.out.println(end.distance);
    }
  }
}
class Grid {
  public char spot;
  public int distance;
  public boolean isStart;
  public boolean isEnd;
  public Grid(char spot, int distance, boolean isStart, boolean isEnd) {
    this.spot = spot;
    this.distance = isStart ? 1: distance;
    this.isStart = isStart;
    this.isEnd = isEnd;
  }
  public String toString() {
    return "(" + spot + "- dist: " + distance + " start: " + isStart + " end: " + isEnd + ")";
  }
}
