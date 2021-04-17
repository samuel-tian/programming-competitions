import java.io.*;
import java.util.*;

public class Tic {

  public static char isWin(char[][] grid) {
    // check rows
    for (int r = 0; r < 3; ++r) {
      if (grid[r][0] == '.')
        continue;
      if (grid[r][0] == grid[r][1]
          && grid[r][1] == grid[r][2])
        return grid[r][0];
    }

    // check cols
    for (int c = 0; c < 3; ++c) {
      if (grid[0][c] == '.')
        continue;
      if (grid[0][c] == grid[1][c]
          && grid[1][c] == grid[2][c])
        return grid[0][c];
    }

    // check cols
    if (grid[0][0] != '.'
        && grid[0][0] == grid[1][1]
        && grid[1][1] == grid[2][2])
      return grid[0][0];
    if (grid[0][2] != '.'
        && grid[0][2] == grid[1][1]
        && grid[1][1] == grid[2][0])
      return grid[1][1];

    return '.';
  }

  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(new File("tic.dat"));
    int numTests = in.nextInt();
    in.nextLine();
    for (int z = 0; z < numTests; ++z) {
      char[][] grid = {in.nextLine().toCharArray(),
                       in.nextLine().toCharArray(),
                       in.nextLine().toCharArray()};

      boolean hasEmpty = false;
      char result = '.';
      outerloop:
      for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
          if (grid[r][c] == '.')
            hasEmpty = true;
          result = isWin(grid);
          if (result != '.')
            break outerloop;
        }
      }

      if (result != '.')
        System.out.printf("%c WINS\n", result);
      else if (!hasEmpty)
        System.out.println("DRAW");
      else
        System.out.println("ONGOING");
    }
  }
}
