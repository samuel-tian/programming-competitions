import java.io.*;
import java.util.*;

public class Slugging {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("slugging.dat"));
        int numSets = s.nextInt();
        s.nextLine();
        String allowableChar = "OSDTHW";
        String hitTypes = "SDTH";
        for(int i = 1; i <= numSets; i++){
            int[] hits = new int[4];
            int atBats = 0;
            String results = s.nextLine();
            for(int j = 0; j < results.length(); j++){
                char c = results.charAt(j);
                assert allowableChar.contains(c + "") : "illegal char";
                if(c != 'W') {
                    atBats++;
                    if(c != 'O')
                        hits[hitTypes.indexOf(c)]++;
                }
            }
            if(atBats == 0)
                System.out.println("NONE");
            else {
                double bases = 0;
                for(int j = 0; j < hits.length; j++)
                    bases += hits[j] * (j + 1);
                System.out.printf("%5.3f", (bases / atBats));
                System.out.println();
                // System.out.println(bases / atBats);
            }
        }
        s.close();
    }
}