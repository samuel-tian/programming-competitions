
import java.util.*;
import java.io.*;

public class History
{
  static int maxScore = -1;

  public static int checkScore (int[] a)
  {
    // check blanks in array a represented by -1
    int numOne = 0;
    for (int i = 0; i < a.length; i++)
      if (a[i] == -1)
        numOne++;
    if (numOne == a.length)
      return 0;
    
    // create new array
    int[] b = new int [a.length - numOne];

    // populate b
    int j = 0;
    for (int i = 0; i < a.length; i++)
    {
      if (a[i] > -1)
        b[j++] = a[i];
    }

    // get score
    int score = 1;
    for (int k = 1; k < b.length; k++)
    {
      if (b[k - 1] < b[k])
        score++;
      else
        break;
    }
    return score;
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

  public static void getScore (int[] events, int[] spare, int idx)
  {
    if (idx == events.length)
    {
      int score = checkScore (spare);
      if (score > maxScore)
        maxScore = score;
    }
    else
    {
       int[] spareCopy = copyArray (spare);
       spare[idx] = events[idx];
       getScore (events, spare, idx + 1);
       getScore (events, spareCopy, idx + 1);
    }
  }

  public static void main (String[] args) throws IOException
  {
    // open file history.dat for reading
    File inFile = new File ("history.dat");
    Scanner sc = new Scanner (inFile);

    // read the number of questions and number of events
    String line = sc.nextLine();
    line = line.trim();
    String[] dataSet = line.split ("\\s+");
    int numQues = Integer.parseInt (dataSet[0]);
    int numEvents = Integer.parseInt (dataSet[1]);

    // read each question 
    for (int i = 0; i < numQues; i++)
    {
      // read the sequence of events
      line = sc.nextLine();
      line = line.trim();
      String[] eventList = line.split ("\\s+");

      int[] events = new int [numEvents];
      for (int j = 0; j < numEvents; j++)
      {
        events[j] = Integer.parseInt (eventList[j]);	
      }

      int[] spare = new int [numEvents];
      Arrays.fill (spare, -1);
      maxScore = -1;

      getScore (events, spare, 0);
      System.out.println (maxScore);
    }

    // close the file
    sc.close();
  } 
}
