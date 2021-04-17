
import java.util.*;
import java.io.*;

public class Festivals
{
  public static void main (String[] args) throws IOException
  {
    // open file festivals.dat for reading
    File inFile = new File ("festivals.dat");
    Scanner sc = new Scanner (inFile);

    // read number of inputs
    String line = sc.nextLine();
    line = line.trim();
    int numLines = Integer.parseInt (line);

    // read each line of input and process the data
    for (int i = 0; i < numLines; i++)
    {
      line = sc.nextLine();
      line = line.trim();
      int year = Integer.parseInt (line);
      
      boolean isLeap = (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
      if (isLeap)
      {
         System.out.println (year +" is a leap year.");
	     if (year % 18 == 0)
	     {
            System.out.println (year + " is a Brimborion festival year.");
	     }
      }
      else
      {
        if (year % 25 == 0)
	    {
          System.out.println (year + " is a Narishkeit festival year.");
	    }
	    else
	    {
          System.out.println (year + " is an ordinary year.");
	    }
      }
      System.out.println();
    }

    // close the file
    sc.close();
  } 
}
