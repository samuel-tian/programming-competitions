import java.io.*;
import java.util.*;

public class Change {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("change.dat"));
        int numSets = s.nextInt();
        s.nextLine();
        int[] cents = {1, 5, 10, 25, 50, 100, 100, 200, 500, 1000, 2000, 5000, 10000};
        for(int i = 1; i <= numSets; i++){
            String[] amounts = s.nextLine().trim().split("\\s+");
            assert amounts.length == 13;
            assert amounts.length == cents.length;
            int total = 0;
            for(int j = 0; j < cents.length; j++)
                total += cents[j] * Integer.parseInt(amounts[j]);
            System.out.println(total / 100);
        }
        s.close();
    }
}
