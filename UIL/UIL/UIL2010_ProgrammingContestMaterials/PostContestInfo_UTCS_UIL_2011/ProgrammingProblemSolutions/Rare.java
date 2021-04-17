import java.io.*;
import java.util.*;

public class Rare {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("rare.dat"));
        int numSets = s.nextInt();
        s.nextLine();

        for(int i = 1; i <= numSets; i++){
            double[] freqs = new double[127];
            s.nextLine(); // skip over the dataset number
            String data = s.nextLine();
            for(int j = 0; j < data.length(); j++)
                freqs[data.charAt(j)]++;
            int numRares = 0;
            String rares = "";
            for(int j = 33; j < freqs.length; j++)
                if( freqs[j] != 0 && freqs[j] < data.length() / 25.0) {
                    numRares++;
                    rares += (char) j;
                }
            System.out.println("data set " + i + ", " + numRares + ":" + rares);
        }
        s.close();
    }
}

