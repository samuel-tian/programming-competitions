
import java.util.*;
import java.io.*;

public class Consonant
{
  // remove digits and punctuation marks
  public static String filterString (String s)
  {
    s = s.toLowerCase();
    String st = "";
    for (int i = 0; i < s.length(); i++)
    {
      char ch = s.charAt (i);
      if ((ch >= 'b') && (ch <= 'z') && (ch != 'e') && 
          (ch != 'i') && (ch != 'o') && (ch != 'u'))
      {
        st = st + ch;
      }
    }
    return st;
  }

  // find the longest run of ascending consonants
  public static int incrRun (String s)
  {
    if (s.length() == 0)
      return 0;
    
     int maxRun = 0;
     char lastCh = s.charAt (0);
     int currentRun = 1;
     for (int i = 1; i < s.length(); i++)
     {
       char ch = s.charAt (i);
       if (ch >= lastCh)
       {
         currentRun++;
       }
       else
       {
         if (currentRun > maxRun)
           maxRun = currentRun;
         currentRun = 1;
       }
       lastCh = ch;
     }
     if (currentRun > maxRun)
       maxRun = currentRun;
     return maxRun;
  }

  // find the longest run of descending consonants
  public static int decrRun (String s)
  {
    if (s.length() == 0)
      return 0;
    
     int maxRun = 0;
     char lastCh = s.charAt (0);
     int currentRun = 1;
     for (int i = 1; i < s.length(); i++)
     {
       char ch = s.charAt (i);
       if (ch <= lastCh)
       {
         currentRun++;
       }
       else
       {
         if (currentRun > maxRun)
           maxRun = currentRun;
         currentRun = 1;
       }
       lastCh = ch;
     }
     if (currentRun > maxRun)
       maxRun = currentRun;
     return maxRun;
  }

  public static void main (String[] args) throws IOException
  {
    // open file consonant.dat for reading
    File inFile = new File ("consonant.dat");
    Scanner sc = new Scanner (inFile);

    // read number of inputs
    String line = sc.nextLine();
    line = line.trim();
    int numLines = Integer.parseInt (line);

    // read the number of lines specified and process
    for (int i = 0; i < numLines; i++)
    {
      line = sc.nextLine();
      line = line.trim();
      line = filterString (line);
      
      // get longest ascending and descending runs of consonants
      int maxIncr = incrRun (line);
      int maxDecr = decrRun (line);
   
      // print longest consonant run
      int maxRun = (maxIncr > maxDecr) ? maxIncr : maxDecr;
      System.out.println (maxRun);
    }

    // close the file
    sc.close();
  } 
}
