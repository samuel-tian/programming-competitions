
import java.util.*;
import java.io.*;

public class Base
{
  public static String sumTerms (int num, int[] fib)
  {
    String s = "";
    int sum = 0;

    int idx = fib.length - 1;
    while (sum < num)
    {
      if ((fib[idx] + sum) <= num)
      {
        if (sum == 0)
	      s = String.valueOf (fib[idx]);
	    else
	      s = s + " + " + String.valueOf (fib[idx]);
	    sum = sum + fib[idx];
	    idx = idx - 2;
      }
      else
        idx = idx - 1;
    }

    return s;
  }
  public static void main (String[] args) throws IOException
  {
    // find n for which the nth Fibonacci term is greater than 1000
    int n = 2;
    int f0 = 0;
    int f1 = 1;
    int f = f0 + f1;
    while (f < 1000)
    {
      f0 = f1;
      f1 = f;
      f = f0 + f1;
      n++;
    }

    // create an array to hold n terms of the Fibonacci series
    int[] fib = new int [n];

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++)
    {
      fib[i] = fib[i - 1] + fib[i - 2];
    }

    // open file base.dat for reading
    File inFile = new File ("base.dat");
    Scanner sc = new Scanner (inFile);


    // read each line of input and process the data
    while (sc.hasNextLine())
    {
      String line = sc.nextLine();
      line = line.trim();
      int num = Integer.parseInt (line);
      String terms = sumTerms (num, fib);
      System.out.println (num + " = " + terms);
    }

    // close the file
    sc.close();
  } 
}
