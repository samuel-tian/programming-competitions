
import java.util.*;
import java.io.*;

public class Palindromes
{

  public static String filterString (String st)
  {
    st = st.toLowerCase();

    // create empty string and add only letters
    String s = "";
    for (int i = 0; i < st.length(); i++)
    {
      char ch = st.charAt (i);
      if ((ch >= 'a') && (ch <= 'z'))
        s += ch;
    }
    return s;
  }

  public static boolean isPalin (String st)
  {
    int slen = st.length();
    for (int i = 0; i < slen / 2; i++)
    {
      if (st.charAt(i) != st.charAt (slen - i - 1))
        return false;
    }

    return true;
  }

  public static int maxPalin (String st)
  {
    st =  filterString (st);
    if (st.length() == 0)
      return 0;

    int wnd = st.length();
    while (wnd > 1)
    {
      int index = 0;
      while ((index + wnd) <= st.length())
      {
        String substr = st.substring (index, index + wnd);
	if (isPalin(substr))
	  return wnd;

	index++;
      }
      wnd--;
    }
    return wnd;
  }

  public static void main (String[] args) throws IOException
  {
    // open file palindromes.dat for reading
    File inFile = new File ("palindromes.dat");
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
      System.out.println (maxPalin (line));
    }

    // close the file
    sc.close();
  } 
}
