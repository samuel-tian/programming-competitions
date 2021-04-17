import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;
/**
 * Given a list of things return all the possible permutations you can make.
 * @author sno
 *
 */

class Pedro {
	public static void main(String [] args) throws FileNotFoundException {
		Scanner f = new Scanner(new File("pedro.dat"));
		while(f.hasNextLine()) {
			set = new ArrayList<String[]>();
			exist = new TreeSet<String>();
			String [] input = f.nextLine().split(" ");
			int num = Integer.parseInt(input[0]);
			String [] fruits = Arrays.copyOfRange(input, 1, input.length);
			Arrays.sort(fruits);
			permute(fruits, new String[0], num);

			for(String[] str: set){
				for(int i = 0; i < str.length; i++) {
					System.out.print(str[i] + " ");
				}
				System.out.println();
			}
			System.out.println();
		}
	}

	public static ArrayList<String[]> set = new ArrayList<String[]>();
	public static TreeSet<String> exist = new TreeSet<String>();
	public static void permute(String [] prefix, String [] suffix, int len) {
		if(len == 0) {
			Arrays.sort(suffix);
			String str = toString(suffix);
			if(exist.contains(str)){
				return;
			}
			exist.add(str);
			set.add(suffix);
			return;
		}

		for(int i = 0; i < prefix.length; i ++) {
			String [] newPrefix = new String[prefix.length - 1];
			String [] newSuffix = new String[suffix.length + 1];
			for(int j = 0; j < i; j ++ ){
				newPrefix[j] = prefix[j];
			}
			for(int j = i+1; j < prefix.length; j++) {
				newPrefix[j-1] = prefix[j];
			}
			newSuffix[0] = prefix[i];
			for(int j = 0; j < suffix.length; j++) {
				newSuffix[j+1] = suffix[j];
			}
			permute(newPrefix, newSuffix, len-1);
		}
	}

	public static String toString(String [] in){
		String ret = "";
		for(String s: in) {
			ret += " " + s;
		}
		return ret;
	}
}
