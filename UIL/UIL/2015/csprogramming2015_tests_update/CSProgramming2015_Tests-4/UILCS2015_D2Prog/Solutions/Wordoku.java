
import java.util.*;
import java.io.*;

public class Wordoku
{
  public static boolean isValid (char[][] grid)
  {
    // get dimension of grid
    int dim = grid.length;

    // get first row
    char[] firstRow = new char [dim];
    for (int j = 0; j < dim; j++)
      firstRow[j] = grid[0][j];

    // sort first row
    Arrays.sort (firstRow);
    String firstRowStr = new String (firstRow);

    // check if all the characters are different
    for (int i = 1; i < dim; i++)
    {
      if (firstRow[i - 1] == firstRow[i])
        return false;
    }

    // check if all rows are the same
    for (int i = 1; i < dim; i++)
    {
      // get next row
      char[] nextRow = new char [dim];
      for (int j = 0; j < dim; j++)
        nextRow[j] = grid[i][j];

      Arrays.sort (nextRow);
      String nextRowStr = new String (nextRow);
      if (!firstRowStr.equals (nextRowStr))
        return false;
    }

    // check if all columns are the same
    for (int j = 0; j < dim; j++)
    {
      char[] col = new char [dim];
      for (int k = 0; k < dim; k++)
      {
        col[k] = grid[k][j];
      }
      Arrays.sort (col);
      String nextColStr = new String (col);
      if (!firstRowStr.equals(nextColStr))
        return false;
    }

    // return true since it passed all tests
    return true;
  }

  public static void main (String[] args) throws IOException
  {
    // open file wordoku.dat for reading
    File inFile = new File ("wordoku.dat");
    Scanner sc = new Scanner (inFile);

    // read number of grids to test
    String line = sc.nextLine();
    line = line.trim();

    int numGrids = Integer.parseInt (line);
    for (int i = 0; i < numGrids; i++)
    {
      // read dimension of grid
      line = sc.nextLine();
      line = line.trim();
      int dim = Integer.parseInt (line);

      // create a grid of chars
      char[][] grid = new char[dim][dim];

      // read input and populate the grid
      for (int j = 0; j < dim; j++)
      {
        line = sc.nextLine();
	line = line.trim();
	String[] charList = line.split("\\s+");
	for (int k = 0; k < dim; k++)
	{
          grid[j][k] = (charList[k]).charAt(0);
	}
      }

      // check if it is a valid Wordoku grid and print result
      if (isValid (grid))
        System.out.println ("VALID");
      else
        System.out.println ("INVALID");

      // read blank line
      line = sc.nextLine();
    }

    // close the file
    sc.close();
  } 
}
