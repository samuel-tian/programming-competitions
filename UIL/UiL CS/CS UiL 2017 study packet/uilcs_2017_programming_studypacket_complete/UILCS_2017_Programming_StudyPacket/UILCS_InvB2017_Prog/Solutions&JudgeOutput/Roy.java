import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.TreeMap;

/**
 * Given a list of cards that are picked up, keeping 5 cards in hand at all time, and removing the card of the
 * least number of occurrences and value, display the hand at the end of the game.
 */
public class Roy {
	public static void main(String [] args) throws FileNotFoundException {
		Scanner f = new Scanner(new File("roy.dat"));
		while(f.hasNextLine()) {
			String line = f.nextLine();
      line = line.replaceAll("A", "E");
      line = line.replaceAll("K", "D");
      line = line.replaceAll("Q", "C");
      line = line.replaceAll("J", "B");
      line = line.replaceAll("10", "A");
			Scanner chop = new Scanner(line);
			TreeMap<Character, Integer> hand = new TreeMap<Character, Integer>();
			int num = 0;
			while(chop.hasNext()) {
				char card = chop.next().charAt(0);
				addCard(hand, card);
				if(num >= 5)
					removeLowestCard(hand);
				num ++;
			}
			displayHand(hand);
		}
	}

	/*
	 * removes the card with the least number of occurrences in the hand, if there is a tie,
	 * it removes one of lesser value
	 */
	private static void removeLowestCard(TreeMap<Character, Integer> hand) {
		char lowestAndLeast = 'Z';
		int occurrences = 10;
		for(char card: hand.keySet()) {
			if(hand.get(card) < occurrences) {
				occurrences = hand.get(card);
				lowestAndLeast = card;
			}

			if(hand.get(card) == occurrences && lowestAndLeast > card) {
				lowestAndLeast = card;
			}
		}

		hand.put(lowestAndLeast, occurrences - 1);
		if(occurrences - 1 == 0) {
			hand.remove(lowestAndLeast);
		}
	}

	/*
	 * Adds the newest card to the hand
	 */
	private static void addCard(TreeMap<Character, Integer> hand, char card) {
		if(hand.get(card) == null) {
			hand.put(card, 1);
		} else {
			hand.put(card, hand.get(card) + 1);
		}
	}

	/*
	 * prints the current hand to the screen in order of least to greatest
	 */
	private static void displayHand(TreeMap<Character, Integer> hand) {
		for(char card: hand.keySet()) {
			for(int i = 0; i < hand.get(card); i++) {
        String pcard = card + "";
        if(card == 'A') {
          pcard = "10";
        }

        if(card == 'B') {
          pcard = "J";
        }

        if(card == 'C') {
          pcard = "Q";
        }

        if(card == 'D') {
          pcard = "K";
        }

        if(card == 'E') {
          pcard = "A";
        }
				System.out.print(pcard + " ");
			}
		}
		System.out.println();
	}
}
