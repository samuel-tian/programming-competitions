
import java.io.*;
import java.util.*;

public class Rock {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("rock.dat"));
        int numSets = s.nextInt();
        s.nextLine();
        String[] weaponsInput = {"*********", "---***---", "**---***-", "-***-*-*-", "*-**-*-*-"};
        String[] weapons = {"Rock", "Paper", "Scissors", "Lizard", "Spock"};
        int[][] results = {{0, 2, 1, 1, 2}, {1, 0, 2, 2, 1}, {2, 1, 0, 1, 2}, {2, 1, 2, 0, 1}, {1, 2, 1, 2, 0}};
        String[][] outcomes = {{"Tie", "COVERS", "CRUSHES", "CRUSHES", "VAPORIZES"},
                               {"COVERS", "Tie", "CUTS", "EATS", "DISPROVES"},
                               {"CRUSHES", "CUTS", "Tie","DECAPITATES", "SMASHES"},
                               {"CRUSHES", "EATS", "DECAPITATES", "Tie", "POISONS"},
                               {"VAPORIZES", "DISPROVES", "SMASHES", "POISONS", "Tie"}};

        for(int i = 1; i <= numSets; i++){
            System.out.println("Game " + i + ":");
            int rounds = s.nextInt();
            s.nextLine();
            int p1Wins = 0;
            int p2Wins = 0;
            for(int j = 0; j < rounds; j++){
                String p1Weapon = "";
                String p2Weapon = "";
                for(int k = 0; k < 3; k++){
                    String temp = s.nextLine().trim();
                    p1Weapon += temp.substring(0,3);
                    p2Weapon += temp.substring(4);
                }
                int p1Choice = findWeapon(p1Weapon, weaponsInput);
                int p2Choice = findWeapon(p2Weapon, weaponsInput);
                if(p1Choice == -1 && p2Choice == -1)
                    System.out.println("Both players picked invalid weapons. Tie.");
                else if( p1Choice == -1 ){
                    System.out.println("Player 1 picked an invalid weapon. Player 2 wins.");
                    p2Wins++;
                }
                else if(p2Choice == -1){
                    System.out.println("Player 2 picked an invalid weapon. Player 1 wins.");
                    p1Wins++;
                }
                else if(p1Choice == p2Choice)
                    System.out.println("Both players picked " + weapons[p1Choice] + ". Tie.");
                else{
                    int winner = results[p1Choice][p2Choice];
                    String outcome = outcomes[p1Choice][p2Choice];
                    if(winner == 1){
                        System.out.println(weapons[p1Choice] + " " + outcome + " " + weapons[p2Choice] + ". Player 1 wins.");
                        p1Wins++;
                    }
                    else{
                        System.out.println(weapons[p2Choice] + " " + outcome + " " + weapons[p1Choice] + ". Player 2 wins.");
                        p2Wins++;
                    }
                }
            }
            System.out.print("Player 1: " + p1Wins + ", Player 2: " + p2Wins +", Ties: " + (rounds - p1Wins - p2Wins) + ". ");
            if(p1Wins > p2Wins)
                System.out.println("Result: Player 1 wins.");
            else if(p2Wins > p1Wins)
                System.out.println("Result: Player 2 wins.");
            else
                System.out.println("Result: Tie.");
        }
        s.close();
    }

    private static int findWeapon(String weapon, String[] weaponsInput) {
        for(int i = 0; i < weaponsInput.length; i++)
            if(weapon.equals(weaponsInput[i]))
                return i;
        return -1;
    }
}
