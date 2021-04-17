
import java.util.*;
import java.io.*;

public class Bitmap
{

  
  public static int sumOnes (int[][] bitmap, int x1, int y1, int x2, int y2)
  {
    int sum = 0;
    for (int i = x1; i <= x2; i++)
    {
      for (int j = y1; j <= y2; j++)
      {
        if (bitmap[i][j] == 0)
	  return 0;
	else
	  sum += 1;
      }
    }
    return sum;
  }

  public static int allOnes (int[][] bitmap)
  {
    // get dimension of the bitmap
    int numR = bitmap.length;
    int numC = bitmap[0].length;

    // initialize max area
    int maxArea = 0;

    for (int x1 = 0; x1 < numR; x1++)
    {
      for (int y1 = 0; y1 < numC; y1++)
      {
        for (int x2 = x1; x2 < numR; x2++)
	{
          for (int y2 = y1; y2 < numC; y2++)
	  {
            
	    int numOnes = sumOnes (bitmap, x1, y1, x2, y2);
	    if (numOnes > maxArea)
	      maxArea = numOnes;
	  }
	}
      }
    }
    return maxArea;
  }

  public static void main (String[] args) throws IOException
  {
    // open file bitmap.dat for reading
    File inFile = new File ("bitmap.dat");
    Scanner sc = new Scanner (inFile);

    // read the dimensions of the bitmap
    String line = sc.nextLine();
    line = line.trim();
    Scanner dimLine = new Scanner (line);
    int numR = dimLine.nextInt();
    int numC = dimLine.nextInt();

    // read and create the bitmap
    int[][] bitmap = new int [numR][numC];
    for (int i = 0; i < numR; i++)
    {
      line = sc.nextLine();
      line = line.trim();
      for (int j = 0; j < numC; j++)
      {
        bitmap[i][j] = line.charAt(j) - '0';
      }
    }

    // determine area of the largest rectangle containing all ones

    System.out.println (allOnes(bitmap));

    // close the file
    sc.close();
  } 
}
