import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;

public class Manuela {
	public static boolean DEBUG = false;
	public static void main(String [] args) throws FileNotFoundException {
		Scanner f = new Scanner(new File("manuela.dat"));
		int N = f.nextInt(); f.nextLine();
		while(N-- > 0) {
			solutionBucket = new HashMap<Integer, Tup>();
			bestAmount = Integer.MAX_VALUE;

			int coins = f.nextInt();
			int [] denominations = new int[coins];
			String [] names = new String[coins];
			HashMap<String, Integer> occurences = new HashMap<String, Integer>();

			for(int i = 0; i < coins; i++) {
				names[i] = f.next();
				denominations[i] = f.nextInt();
				occurences.put(names[i], 0);
			}
			int amount = f.nextInt();

			makeChange(denominations, names, amount, occurences, 0);
			if(DEBUG) {
				System.out.println(solutionBucket);
			} else {
				processOutput(solutionBucket.get(0).left);
			}
		}
		f.close();
	}

	private static HashMap<Integer, Tup> solutionBucket= new HashMap<Integer, Tup>();
	private static int bestAmount = Integer.MAX_VALUE;

	public static void makeChange(int [] values, String [] names, int curAmount, HashMap<String, Integer> soFar, int numberOfCoins) {
		if(curAmount < 0 || numberOfCoins > bestAmount) {
			return;
		}

		if(solutionBucket.containsKey(curAmount)) {
			Tup tup = solutionBucket.get(curAmount);

			if(tup.right > numberOfCoins) {
				tup.right = numberOfCoins;
				tup.left = soFar;
			} else {
				return;
			}
		} else {
			solutionBucket.put(curAmount, new Tup(soFar, numberOfCoins));
		}

		if(curAmount == 0 && numberOfCoins < bestAmount) {
			bestAmount = numberOfCoins;
		}

		for(int i = 0; i < values.length; i++) {
			HashMap<String, Integer> soFar2 = new HashMap<String,Integer>(soFar);
			soFar2.put(names[i], soFar.get(names[i]) + 1);

			makeChange(values, names, curAmount - values[i], soFar2, numberOfCoins + 1);
		}
	}

	/*
	 * Formats output
	 */
	public static void processOutput(HashMap<String, Integer> occurrences) {
		TreeMap<String, Integer> map = new TreeMap<String, Integer>(occurrences);
		for(String a : map.keySet()) {
			if(map.get(a) > 0) {
				System.out.print(a +": " + map.get(a) + " ");
			}
		}
		System.out.println();
	}
}

class Tup {

	public HashMap<String,Integer> left;
	public int right;

	public Tup(HashMap<String,Integer> map, int in) {
		left = map;
		right = in;
	}
	public String toString() {
		return "(" + left + ", " + right + ")";
	}
}
