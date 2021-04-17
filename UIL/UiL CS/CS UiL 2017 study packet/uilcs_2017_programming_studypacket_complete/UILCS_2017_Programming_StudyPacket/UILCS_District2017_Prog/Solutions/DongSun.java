import java.util.*;
import java.io.*;

public class DongSun {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner f = new Scanner(new File("dongsun.dat"));
        int N = f.nextInt();
        while(N-- >0 ) {
          int numApplications = f.nextInt();
          Pair[] bridgeApplications = new Pair[numApplications + 1];
          Pair[] originalBridgeApplications = new Pair[numApplications + 1];
          //first position holds a dummy
          bridgeApplications[0] = new Pair(0,0);
          originalBridgeApplications[0] = new Pair(0,0);
          for(int i = 1; i < numApplications + 1; i++) {
            int north = f.nextInt();
            f.next(); // grab the center token
            int south = f.nextInt();
            bridgeApplications[i] = new Pair(north, south);
            originalBridgeApplications[i] = bridgeApplications[i];
          }
          Arrays.sort(bridgeApplications);
          // debug print
          /*for(Pair p: bridgeApplications) {
            System.out.println(p.northSide + " " + p.southSide);
          }*/
          String out = "Approved Applications: ";

          Pair[] result = lis(bridgeApplications);
          for (int i = 0; i < originalBridgeApplications.length; i++)
              for(int j = 0; j < result.length; j++) {
                if(originalBridgeApplications[i].equals(result[j])) {
                  out += result[j].northSide + " -> " + result[j].southSide + ", ";
                }
              }
          System.out.println(out.substring(0, out.length()-2));
        }
    }
    // Longest increasing subsequence calculation
    public static Pair[] lis(Pair[] X) {
        int n = X.length - 1;
        int[] M = new int[n + 1];
        int[] P = new int[n + 1];
        int L = 0;

        for (int i = 1; i < n + 1; i++) {
            int j = 0;

            for (int pos = L ; pos >= 1; pos--) {
                if (X[M[pos]].southSide <= X[i].southSide)
                {
                    j = pos;
                    break;
                }
            }
            P[i] = M[j];
            if (j == L || X[i].southSide <= X[M[j + 1]].southSide) {
                M[j + 1] = i;
                L = Math.max(L,j + 1);
            }
        }

        /** backtrack **/
        Pair[] result = new Pair[L];
        int pos = M[L];
        for (int i = L - 1; i >= 0; i--) {
            result[i] = X[pos];
            pos = P[pos];
        }
        return result;
    }
}

class Pair implements Comparable{
  int northSide = -1;
  int southSide = -1;
  public Pair(int north, int south) {
    northSide = north;
    southSide = south;
  }
  public int compareTo(Object o) {
    Pair p = (Pair)o;
    return this.northSide - p.northSide;
  }
}
