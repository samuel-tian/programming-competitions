

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Set;
import java.util.HashSet;
import java.util.Scanner;
/**
 * 
 * @author sno
 *
 * Given a list of words and word find out if the given word is made up of a compound of two of the other words. (scale)
 *
 */
public class Emiliano {
	
	public static void main(String [] args) throws FileNotFoundException {
		Scanner fin = new Scanner(new File("emiliano.dat"));
		int datasets = fin.nextInt();
		
		for (int i = 0; i < datasets; i++) {
			int numWords = fin.nextInt();
			fin.nextLine();
			int count = 0;
			Set<String> dict = new HashSet<String>();

			int min = Integer.MAX_VALUE;
			for (int j = 0; j < numWords; j++) {
				String word = fin.nextLine().toUpperCase();
				dict.add(word);
				min = Math.min(min, word.length());
			}
			
			int numCases = fin.nextInt();
			fin.nextLine();
			
			for (int j = 0; j < numCases; j++) {
				String test = fin.nextLine().toUpperCase();
				
				for (int k = min; k <= test.length() - min; k++) {
					String a = test.substring(0, k);
					String b = test.substring(k);
					if (dict.contains(a) && dict.contains(b)) {
							//System.out.println(test + " is a compound word of " + a + " and " + b + ".");
							count += 1;
					}
				}
			}
			System.out.println(count);
		}
		
		fin.close();
	}
}
