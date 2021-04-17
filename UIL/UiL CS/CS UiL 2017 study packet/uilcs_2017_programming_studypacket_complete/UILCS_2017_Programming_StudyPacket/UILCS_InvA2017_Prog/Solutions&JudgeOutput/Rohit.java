import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.Scanner;

class Rohit {
  public static void main(String[] args) throws FileNotFoundException {
    Scanner f = new Scanner(new File("rohit.dat"));
    int N = f.nextInt();f.nextLine();
    while(N-- > 0) {
      String levelsStr = "1 " + f.nextLine();
      String [] levels = levelsStr.split(" ");
      int [] branches = new int[levels.length];
      ArrayList<ArrayList<Integer>> tree = new ArrayList<>();
      for(int i = 0; i < branches.length; i++) {
        branches[i] = Integer.parseInt(levels[i]);
        tree.add(new ArrayList<>());
      }
      int currentValue = 0;
      for(int i = 0; i < branches.length; i++) {
        for(int j = 0; j < levelLength(branches, i+1); j++) {
          tree.get(i).add(currentValue++);
        }
      }
      // DEBUG PRINT
      // for(int i = 0; i < branches.length; i++) {
      //   System.out.println();
      //   for(int j = 0; j < levelLength(branches, i+1); j++) {
      //     System.out.print(tree.get(i).get(j) + " ");
      //   }
      // }

      findAndPrintChildren(branches, tree, Integer.parseInt(f.nextLine()));
    }
  }

  public static int levelLength(int [] branches, int limit) {
    int sum = 1;
    for(int i = 0; i < limit; i++) {
      sum *= branches[i];
    }
    return sum;
  }

  public static void findAndPrintChildren(int[] branches, ArrayList<ArrayList<Integer>> tree, int search) {
    int level = -1;
    int index = -1;
    for(int i = 0; i < branches.length; i++) {
      for(int j = 0; j < levelLength(branches, i+1); j++) {
        int current = tree.get(i).get(j);
        if(search == current) {
          level = i;
          index = j;
        }
      }
    }
    if(index == -1 || level == -1) {
      System.out.println("NOT IN TREE");
      return;
    }
    try {
      for(int i = 0; i < branches[level+1]; i++) {
        System.out.print(tree.get(level+1).get(i + index * branches[level+1]) + " ");
      }
      System.out.println();
    } catch(ArrayIndexOutOfBoundsException e) {
      System.out.println("NO CHILDREN");
    }
  }
}
