import java.io.*;
import java.util.*;

public class Population {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("population.dat"));
        int numSets = s.nextInt();
        s.nextLine();

        for(int i = 1; i <= numSets; i++){
            // based on Kadane's algorithm
            int numValues = s.nextInt();
            s.nextLine();
            String[] data = s.nextLine().trim().split("\\s+");
            assert numValues == data.length : "Difference between stated and actual number of ints";
            int[] actualData = new int[data.length];
            for(int j = 0; j < actualData.length; j++)
                actualData[j] = Integer.parseInt(data[j]);
            int maxSum = Integer.MIN_VALUE;
            int currentMaxSum = 0;
            for(int j = 0; j < actualData.length; j++) {
                currentMaxSum += actualData[j];
                maxSum = Math.max(maxSum, currentMaxSum);
                currentMaxSum = Math.max(currentMaxSum, 0);
            }
            System.out.println(maxSum);
        }
        s.close();
    }
}
