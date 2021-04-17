import java.io.*;
import java.util.*;

public class Benford {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(new File("benford.dat"));
    int numTests = in.nextInt();
    for (int zz = 0; zz < numTests; ++zz) {
      int numInts = in.nextInt();
      in.nextLine();
      float numOnes = 0;
      for (int z = 0; z < numInts; ++z) {
        numOnes += in.nextLine().charAt(0) == '1' ? 1 : 0;
      }
      float prob = numOnes / numInts * 100;
      if (prob <= 35 && prob >= 25) {
        System.out.println("PASSED");
      } else {
        System.out.printf("FAILED: %.2f%%\n", prob);
      }
    }
  }
}
