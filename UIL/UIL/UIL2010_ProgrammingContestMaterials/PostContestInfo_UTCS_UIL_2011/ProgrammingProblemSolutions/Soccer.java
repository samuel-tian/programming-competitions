import java.io.*;
import java.util.*;

import org.omg.CosNaming.IstringHelper;

public class Soccer {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("soccer.dat"));
        int numSets = s.nextInt();
        s.nextLine();

        for(int i = 1; i <= numSets; i++){
            ArrayList<String> matches = new ArrayList<String>(6);
            for(int j = 0; j < 6; j++)
                matches.add(s.nextLine());
            assert matches.size() == 6;
            ArrayList<Results> teams = getResults(matches);
            assert teams.size() == 4 : teams.size() + "";
            Collections.sort(teams);
            // System.out.println(teams);
            String result = "";
            if(teams.get(0).compareTo(teams.get(1)) < 0 )
                // clear winner?
                result = teams.get(0).name;
            else if(teams.get(0).compareTo(teams.get(2)) == 0)
                // 3 way tie or more?
                result = "UNRESOLVED";
            else {
                // 2 way tie. Find match and see if winner
                String team1 = teams.get(0).name;
                String team2 = teams.get(1).name;
                String match = "";
                int j = 0;
                while(match.length() == 0 && j < teams.size()) {
                    String temp = matches.get(j);
                    if(temp.contains(team1) && temp.contains(team2))
                        match = temp;
                    j++;
                }
                result = breakHeadToHeadTie(match);
            }
            System.out.println("data set " + i + ":" + " " + result );
        }
        s.close();
    }


    private static String breakHeadToHeadTie(String match) {
        String result = "UNRESOLVED";
        String[] data = match.split("\\s+");
        String team1 = data[0];
        int goals1 = Integer.parseInt(data[1]);
        String team2 = data[2];
        int goals2 = Integer.parseInt(data[3]);
        if(goals1 > goals2)
            result = team1;
        else if(goals2 > goals1)
            result = team2;
        return result;
    }


    private static ArrayList<Results> getResults(ArrayList<String> matches) {
        Map<String, Results> teams = new HashMap<String, Results>();
        for(int i = 0; i < matches.size(); i++) {
            String[] data = matches.get(i).split("\\s+");
            String team1 = data[0];
            int goals1 = Integer.parseInt(data[1]);
            String team2 = data[2];
            int goals2 = Integer.parseInt(data[3]);
            // draw okay as flag becuase teams are to be upper case
            String winner = (goals1 > goals2) ? team1 : (goals2 > goals1) ? team2 : "draw";
            Results r1 = (teams.containsKey(team1)) ? teams.get(team1) : new Results(team1);
            Results r2 = (teams.containsKey(team2)) ? teams.get(team2) : new Results(team2);
            r1.goalsScored += goals1;
            r1.goalsAllowed += goals2;
            r2.goalsScored += goals2;
            r2.goalsAllowed += goals1;
            if(winner.equals(team1))
                r1.points += 3;
            else if(winner.equals(team2))
                r2.points += 3;
            else {
                r1.points++;
                r2.points++;
            }
            teams.put(team1, r1);
            teams.put(team2, r2);
        }
        ArrayList<Results> result = new ArrayList<Results>();
        for(String key : teams.keySet())
            result.add(teams.get(key));
        return result;
    }

    private static class Results implements Comparable<Results> {
        private String name;
        private int points;
        private int goalsScored;
        private int goalsAllowed;

        private Results(String n) { name = n; }

        public String scoreIndex () {
            return points + " " + goalDiff() + " " + goalsScored + " " + goalsAllowed;
        }

        public int compareTo(Results other) {
            int result = other.points - points;
            if(result == 0)
                result = other.goalDiff() - goalDiff();
            if(result == 0)
                result = other.goalsScored - goalsScored;
            return result;
        }

        public int goalDiff() {
            return goalsScored - goalsAllowed;
        }

        public String toString() {
            return name + " " + scoreIndex();
        }
    }
}
