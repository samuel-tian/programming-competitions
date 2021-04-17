
import java.io.*;
import java.util.*;

public class Mixup {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("mixup.dat"));
        int numSets = s.nextInt();
        s.nextLine();

        for(int i = 1; i <= numSets; i++){
            String[] words = s.nextLine().trim().split("\\s+");
            for(int j = 0; j < words.length - 1; j++){
                for(int k = words[j].length() - 1; k >= 0; k--)
                    System.out.print(words[j].charAt(k));
                System.out.print(" ");
            }
            // last word, no space
            for(int k = words[words.length - 1].length() - 1; k >= 0; k--)
                System.out.print(words[words.length - 1].charAt(k));
            System.out.println();
        }
        s.close();
    }
}

