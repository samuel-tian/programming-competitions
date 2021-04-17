import java.io.*;
import java.util.*;

public class CardSet {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("cardset.dat"));
        int numSets = s.nextInt();
        s.nextLine();
        String symbols = "^~0";
        String shading = "STN";
        String color = "RGP";
        for(int i = 1; i <= numSets; i++){
            int[][] cards = new int[3][4];
            // read in cards
            for(int j = 0; j < 3; j++) {
                String card = s.nextLine().trim();
                cards[j][0] = card.length() - 2;
                cards[j][1] = symbols.indexOf(card.charAt(0));
                // trim away symbols
                card = card.substring(card.length() - 2, card.length());
                cards[j][2] = shading.indexOf(card.charAt(0));
                cards[j][3] = color.indexOf(card.charAt(1));
            }
            int numValid = 0;
            for(int j = 0; j < cards[0].length; j++) {
                if(cards[0][j] == cards[1][j] && cards[1][j] == cards[2][j])
                    numValid++;
                else if(cards[0][j] != cards[1][j] &&
                        cards[1][j] != cards[2][j] &&
                        cards[0][j] != cards[2][j])
                    numValid++;
            }
            if(numValid == 4)
                System.out.println("SET");
            else
                System.out.println("NOT");
        }
        s.close();
    }
}