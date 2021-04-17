
import java.util.*;
import java.io.*;

public class Blocks
{
  static boolean match = false;
  public static int sumArray (int[] a)
  {
    int sum = 0;
    for (int i = 0; i < a.length; i++)
    {
      if (a[i] != -1)
      {
        sum += a[i];
      }
    }
    return sum;
  }

  public static int[] copyArray (int[] a)
  {
    int[] b = new int [a.length];
    for (int i = 0; i < a.length; i++)
    {
      b[i] = a[i];
    }
    return b;
  }

  public static void canMake (int wall, int[] sizes, int[] spare, int idx)
  {
    if (idx == sizes.length)
    {
      int sum = sumArray (spare);
      if (sum == wall)
      {
        match = true;
	return;
      }
    }
    else
    {
       int[] spareCopy = copyArray (spare);
       spare[idx] = sizes[idx];
       canMake (wall, sizes, spare, idx + 1);
       canMake (wall, sizes, spareCopy, idx + 1);
    }
  }

  public static void main (String[] args) throws IOException
  {
    // open file blocks.dat for reading
    File inFile = new File ("blocks.dat");
    Scanner sc = new Scanner (inFile);

    // read the number of datasets
    String line = sc.nextLine();
    line = line.trim();
    int dataSets = Integer.parseInt (line);

    // read each dataset 
    for (int i = 0; i < dataSets; i++)
    {
      // read length of wall
      line = sc.nextLine();
      line = line.trim();
      int wall = Integer.parseInt (line);

      // read the block sizes
      line = sc.nextLine();
      line = line.trim();
      String[] blockList = line.split ("\\s+");
   
      int[] sizes = new int [blockList.length];
      for (int j = 0; j < blockList.length; j++)
      {
        sizes[j] = Integer.parseInt (blockList[j]);	
      }

      int[] spare = new int [sizes.length];
      Arrays.fill (spare, -1);
      match = false;
      canMake (wall, sizes, spare, 0);
      if (match)
        System.out.println ("YES");
      else
        System.out.println ("NO");
    }

    // close the file
    sc.close();
  } 
}
