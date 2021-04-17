
import java.util.*;
import java.io.*;

public class Odd
{
  public static void main (String[] args) throws IOException
  {
    // open file odd.dat for reading
    File inFile = new File ("odd.dat");
    Scanner sc = new Scanner (inFile);


    // read each line of input and process the data
    while (sc.hasNextLine())
    {
      String line = sc.nextLine();
      line = line.trim();
      int num = Integer.parseInt (line);
      int lineNo = (num + 1) / 2;
      int nextLine = lineNo + 1;
      int firstNum = (2 * nextLine * nextLine) - (4 * nextLine) + 3;
      int sumNum = 3 * firstNum - 12;
      System.out.println (sumNum);
      
    }

    // close the file
    sc.close();
  } 
}
