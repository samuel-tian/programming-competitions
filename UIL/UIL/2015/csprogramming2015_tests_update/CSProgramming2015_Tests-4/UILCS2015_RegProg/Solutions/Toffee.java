
import java.util.*;
import java.io.*;

public class Toffee
{
  public static int maxNumber (int[][] a)
  {
    // create another grid the same size as a
    int dim = a.length;
    int[][] b = new int [dim][dim];
     
    // fill b starting with the bottom row
    for (int j = 0; j < dim; j++)
    {
      b[dim - 1][j] = a[dim - 1][j];
    }

    // fill last column of b
    for (int i = dim - 2; i >= 0; i--)
    {
      b[i][dim - 1] = a[i][dim - 1] + b[i + 1][dim - 1];
    }

    // now fill the rest of b
    for (int i = dim - 2; i >= 0; i--)
    {
      for (int j = 0; j < dim - 1; j++)
      {
        // get max of square directly below or diagonally to the right
	int maxNum = (b[i + 1][j] > b[i + 1][j + 1]) ? b[i + 1][j] :
	                b[i + 1][j + 1];
	b[i][j] = a[i][j] + maxNum;
      }
    }

    // get max sum
    int maxSum = -1;
    for (int j = 0; j < dim; j++)
    {
      if (b[0][j] > maxSum)
        maxSum = b[0][j];
    }
    return maxSum;
  }

  public static void main (String[] args) throws IOException
  {
    // open file for reading
    File inFile = new File ("toffee.dat");
    Scanner sc = new Scanner (inFile);

    // read number of test cases
    String line = sc.nextLine();
    line = line.trim();
    int numCases = Integer.parseInt (line);
   
    for (int cases = 0; cases < numCases; cases++)
    {

      // read dimension of grid
      line = sc.nextLine();
      line = line.trim();
      int dim = Integer.parseInt (line);

      // create array to hold the grid
      int[][] grid = new int[dim][dim];

      for (int i = 0; i < dim; i++)
      {
        line = sc.nextLine();
        line = line.trim();
        String[] numToffees = line.split ("\\s+");
        for (int j = 0; j < dim; j++)
        {
          grid[i][j] = Integer.parseInt (numToffees[j]);
        }
      }
    

      // write out the max count
      System.out.println (maxNumber (grid));
    }

    

    // close file
    sc.close();

  }
}
