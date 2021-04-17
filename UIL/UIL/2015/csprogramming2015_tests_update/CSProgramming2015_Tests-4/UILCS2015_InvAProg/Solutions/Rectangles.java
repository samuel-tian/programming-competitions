
import java.util.*;
import java.io.*;

public class Rectangles
{
  public static boolean isInside (double x1, double y1, double x2, double y2,
                                double x3, double y3, double x4, double y4,
				double x, double y)
  {
    // all the cases where the two rectangles do not intersect
    if (x2 < x3)
      return false;
    if (x4 < x1)
      return false;
    if (y2 > y3)
      return false;
    if (y4 > y1)
      return false;

    // compute the coordinates of the intersection rectangle
    double x_1 = 0.0;
    double y_1 = 0.0;
    double x_2 = 0.0;
    double y_2 = 0.0;

    // determine the x coordinates
    if ((x1 <= x3) && (x3 <= x2) && (x2 <= x4))
    {
      x_1 = x3;
      x_2 = x2;
    }
    else if ((x3 <= x1) && (x1 <= x4) && (x4 <= x2))
    {
      x_1 = x1;
      x_2 = x4;
    }
    else if ((x1 <= x3) && (x4 <= x2))
    {
       x_1 = x3;
       x_2 = x4;
    }
    else if ((x3 <= x1) && (x2 <= x4))
    {
       x_1 = x1;
       x_2 = x2;
    }

    // determine the y coordinates
    if ((y1 >= y3) && (y3 >= y2) && (y2 >= y4))
    {
      y_1 = y3;
      y_2 = y2;
    }
    else if ((y3 >= y1) && (y1 >= y4) && (y4 >= y2))
    {
      y_1 = y1;
      y_2 = y4;
    }
    else if ((y1 >= y3) && (y4 >= y2))
    {
       y_1 = y3;
       y_2 = y4;
    }
    else if ((y3 >= y1) && (y2 >= y4))
    {
       y_1 = y1;
       y_2 = y2;
    }
    

    // check if the point is outside the intersection area
    if ((x <= x_1) || (x >= x_2))
      return false;
    if ((y >= y_1) || (y <= y_2))
      return false;

    // it must be inside
    return true;
  
  }

  public static void main (String[] args) throws IOException
  {
    // open file rectangles.dat for reading
    File inFile = new File ("rectangles.dat");
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
      Scanner scLine = new Scanner (line);

      // read the coordinates of the first rectangle
      double x1 = scLine.nextDouble();
      double y1 = scLine.nextDouble();
      
      double x2 = scLine.nextDouble();
      double y2 = scLine.nextDouble();

      // read the coordinates of the second rectangle
      double x3 = scLine.nextDouble();
      double y3 = scLine.nextDouble();
      
      double x4 = scLine.nextDouble();
      double y4 = scLine.nextDouble();

      // read the coordinates of the point
      double x = scLine.nextDouble();
      double y = scLine.nextDouble();
      
      // check if the point is inside the intersection area
      if (isInside (x1, y1, x2, y2, x3, y3, x4, y4, x, y))
        System.out.println ("YES");
      else
        System.out.println ("NO");
    }

    // close the file
    sc.close();
  } 
}
