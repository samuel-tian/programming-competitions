import java.io.*;
import java.util.*;

public class QBRating {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("qbrating.dat"));
        int numSets = s.nextInt();
        s.nextLine();
        for(int i = 1; i <= numSets; i++){
            String name = s.nextLine().trim();
            final int ATT = Integer.parseInt(s.nextLine().trim());
            int td = 0;
            int yds = 0;
            int ints = 0;
            int comp = 0;
            for(int j = 0; j < ATT; j++) {
                String play = s.nextLine().trim();
                // check if int or inc
                if(play.charAt(0) == 'I') {
                    if(play.equals("INT"))
                        ints++;
                }
                else {
                    comp++;
                    String[] completion = play.split("\\s+");
                    yds += Integer.parseInt(completion[0]);
                    if(completion.length == 2)
                        td++;
                }
            }
            System.out.print(name + " ");
            if(ATT == 0)
                System.out.println("NO RATING");
            else {
                double rating = (8.4 * yds + 330 * td + 100 * comp - 200 * ints) / ATT;
                System.out.println(Math.round(rating));
                // System.out.print(" " + rating);
            }
        }
        s.close();
    }
}
