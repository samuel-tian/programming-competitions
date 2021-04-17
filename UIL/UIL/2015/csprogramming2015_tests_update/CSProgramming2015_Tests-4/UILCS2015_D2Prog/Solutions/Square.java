
import java.util.*;
import java.io.*;

public class Square
{
  public static boolean sumSquares (int n)
  {
    // get starting number to count down from
    int n2 = n / 2;
    int start = (int) Math.sqrt (n2) + 1;
    
    // check if sum squares from starting number adds to n
    while (start > 1)
    {
       int i = start;
       int sum_squares = i * i;
       while (i > 0)
       {
         i--;
	 sum_squares += i * i;
	 if (sum_squares == n)
	   return true;
       }
       start--;
    }

    // did not find a sequence of squares to add up to n
    return false;
  }

  public static boolean isPalindromic (int n)
  {
    int n_orig = n;
    int rev_num = 0;
    while (n > 0)
    {
      rev_num = rev_num * 10 + (n % 10);
      n = n / 10;
    }
    return (n_orig == rev_num);
  }

  public static void main (String[] args) throws IOException
  {
    // open file square.dat for reading
    File inFile = new File ("square.dat");
    Scanner sc = new Scanner (inFile);


    // read each line of input and process the data
    while (sc.hasNextLine())
    {
      String line = sc.nextLine();
      line = line.trim();
      int num = Integer.parseInt (line);

      if ((isPalindromic (num)) && (sumSquares (num)))
      {
        System.out.println ("YES");
      }
      else
      {
        System.out.println ("NO");
      }
    }

    // close the file
    sc.close();
  } 
}
