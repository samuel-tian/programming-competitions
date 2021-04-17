
import java.io.*;
import java.util.*;

public class Scores {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("scores.dat"));
        int numSets = s.nextInt();
        s.nextLine();
        String points= "-KWF--T";

        for(int i = 1; i <= numSets; i++){
            String team1 = s.nextLine();
            String team1Scores = s.nextLine();
            String team2 = s.nextLine();
            String team2Scores = s.nextLine();
            int score1 = getScore(points, team1Scores);
            int score2 = getScore(points, team2Scores);
            System.out.print(team1 + " " + score1 + " " + team2 + " " + score2 + " ");
            if(score1 > score2)
                System.out.print(team1);
            else
                System.out.print(team2);
            System.out.println(" Wins!");
        }
        s.close();
    }

    private static int getScore(String points, String teamScores){
        int result = 0;
        for(int j = 0; j < teamScores.length(); j++){
            if(points.indexOf(teamScores.charAt(j)) == -1)
                result += 2;
            else
                result += points.indexOf(teamScores.charAt(j));
        }
        return result;
    }
}
