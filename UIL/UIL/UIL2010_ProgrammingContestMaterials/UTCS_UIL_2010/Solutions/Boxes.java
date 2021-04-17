
import java.io.*;
import java.util.*;

public class Boxes {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("boxes.dat"));
        int numSets = s.nextInt();
        s.nextLine();

        for(int i = 1; i <= numSets; i++){
            System.out.println("Box Set " + i);
            int numBoxes = s.nextInt();
            s.nextLine();
            int total = 0;
            int[] volumes = new int[numBoxes];
            for(int j = 0; j < numBoxes; j++){
                int w = s.nextInt();
                int h = s.nextInt();
                int l = s.nextInt();
                int v = w * h * l;
                total += v;
                volumes[j] = v;
            }
            System.out.println(total);
            Arrays.sort(volumes);
            System.out.println(volumes[volumes.length - 1] + ", " + volumes[0]);
        }
        s.close();
    }
}
