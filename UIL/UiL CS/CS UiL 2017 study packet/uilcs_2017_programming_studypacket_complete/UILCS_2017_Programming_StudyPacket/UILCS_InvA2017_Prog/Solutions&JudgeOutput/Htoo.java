// Given a series of n lines, find if they have a closed polygon. Determine if it

import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class Htoo {
  public static void main(String [] args) throws FileNotFoundException{
    Scanner f = new Scanner(new File("htoo.dat"));
    int N = f.nextInt(); f.nextLine();
    while(N-- > 0) {
      ArrayList<Point> points = new ArrayList<>();
      for(int x = 0; x < 2; x++) {
        String line = f.nextLine();
        String [] inputPts = line.split(">");
        for(String a: inputPts) {
          Point p = new Point(a);
          points.add(p);
        }
      }
      if(points.size() != 4) {
        System.out.println("BAD INPUT");
      }
      if(Point.intersect(points.get(0), points.get(1), points.get(2), points.get(3))) {
        System.out.println("INTERSECT");
      } else {
        System.out.println("NO INTERSECTION");
      }
    }
  }
}
class Point {
  public double x;
  public double y;
  public Point(String unParsed) {
      String removedParen = unParsed.replace("(", "");
      removedParen = removedParen.replace(")", "");
      removedParen = removedParen.replace(" ", "");
      String [] num = removedParen.split(",");
      if(num.length != 2) {
        System.out.println("BAD INPUT");
      }
      this.x = Double.parseDouble(num[0]);
      this.y = Double.parseDouble(num[1]);
  }
  public String toString() {
    return "(" + x + ", " + y + ")";
  }
  public double getSlope(Point p) {
    return (p.y - this.y)/(p.x - this.x);
  }
  public double getIntercept(Point p){
    return (this.y - this.getSlope(p) * this.x);
  }
  public static boolean intersect(Point p1, Point p2, Point q1, Point q2) {
  //  System.out.println("CHECK FOR:: " + p1 + " " + p2 + " " + q1 + " " + q2);
  //  System.out.println("SLOPES:: " + p1.getSlope(p2) + " " + q1.getSlope(q2));
    if((Double.isInfinite(p1.getSlope(p2)) && Double.isInfinite(q1.getSlope(q2)))) {
  //    System.out.println("BOTH ARE VERTICAL");
      if(p1.x != q1.x) {
  //      System.out.println("BUT ARENT ON THE SAME LINE.");
        return false;
      }
      if(p1.x == q1.x) {
  //      System.out.println("AND ARE ON THE SAME LINE.");
        return isBetween(p1.y, p2.y, q1.y) || isBetween(p1.y, p2.y, q2.y) || isBetween(q1.y, q2.y, p1.y) || isBetween(q1.y, q2.y, p2.y);
      }
    }

    if(Double.isInfinite(p1.getSlope(p2)) ^ Double.isInfinite(q1.getSlope(q2))) {
  //    System.out.println("ONLY ONE IS VERTICAL");
      if(Double.isInfinite(p1.getSlope(p2))) {
        double yIntercept = q1.getSlope(q2) * p1.x + q1.getIntercept(q2);
        return isBetween(p1.y, p2.y, yIntercept);
      }
      if(Double.isInfinite(q1.getSlope(q2))) {
        double yIntercept = p1.getSlope(p2) * q1.x + p1.getIntercept(p2);
        return isBetween(q1.y, q2.y, yIntercept);
      }
    }

    if(p1.getSlope(p2) == q1.getSlope(q2)) {
  //    System.out.println("BOTH ARE PARALLEL");
      if(p1.getIntercept(p2) == q1.getIntercept(q2)) {
  //      System.out.println("AND ARE ON THE SAME LINE.");
        return isBetween(p1.y, p2.y, q1.y) || isBetween(p1.y, p2.y, q2.y) || isBetween(q1.y, q2.y, p1.y) || isBetween(q1.y, q2.y, p2.y);
      }
  //    System.out.println("BUT ARENT ON THE SAME LINE.");
      return false;
    }
  //  System.out.println("CALCULATING INTERCEPT");
    double xIntercept = -(p1.getIntercept(p2) - q1.getIntercept(q2))/(p1.getSlope(p2) - q1.getSlope(q2));
    double yIntercept = p1.getSlope(p2) * xIntercept + p1.getIntercept(p2);
  //  System.out.println("INTERCEPT:: " + xIntercept + " " + yIntercept);

    return (isBetween(p1.y, p2.y, yIntercept) && isBetween(p1.x, p2.x, xIntercept)) &&
           (isBetween(q1.y, q2.y, yIntercept) && isBetween(q1.x, q2.x, xIntercept));
  }
  public static boolean isBetween(double a, double b, double c) {
    if(Math.max(a, b) >= c && Math.min(a, b) <= c) {
      return true;
    }
    return false;

  }
}
