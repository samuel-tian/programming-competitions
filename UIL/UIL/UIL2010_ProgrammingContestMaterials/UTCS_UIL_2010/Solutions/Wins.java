
import java.io.*;
import java.util.*;

public class Wins {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("wins.dat"));
        int numSets = s.nextInt();

        for(int i = 1; i <= numSets; i++){
            System.out.println("Data Set " + i);
            int teams = s.nextInt();
            int numGames = s.nextInt();
            s.nextLine();
            for(int j = 0; j < teams; j++){
                System.out.println(s.nextLine()); // print out team name
                String results = s.nextLine();
                int wins = 0;
                int losses = 0;
                for(int k = 0; k < numGames; k++)
                    if(results.charAt(k) == 'W')
                        wins++;
                    else
                        losses++;
                wins = wins - losses;
                String g = (wins == 1 || wins == -1) ? " game " : " games ";
                if(wins > 0)
                    System.out.println("finished " + wins + g + "over 500");
                else if(wins < 0)
                    System.out.println("finished " + Math.abs(wins) + g + "under 500");
                else
                    System.out.println("finished at 500");
            }
            System.out.println();
        }
        s.close();
    }
}
