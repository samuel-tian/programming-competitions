import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Using the nth value of the bit-string fibonnaci sequence, find the number of instances in that bit-string.
 * @author sno
 *
 */
class Evelyn {
	public static void main(String [] args) throws FileNotFoundException {
		Scanner f = new Scanner(new File("evelyn.dat"));
		while(f.hasNextInt()) {

		/*	for(int i = 0; i < 10; i ++) {
				System.out.print(i);
				System.out.print((char)((i+ "").charAt(0)-10));
			}
		//	System.out.println();*/


			//init
			int a = 1;
			int b = 1;
			int n = a + b;
			int max = f.nextInt();
			String val = a + " " + b + " ";

			if(max == 0) {
				System.out.println("\'");
				continue;
			}
			if(max == 1) {
				System.out.println("\' \'");
				continue;
			}

			//fibonnaci calculation
			for(int i = 0; i < max-1; i ++) {
				a = b;
				b = n;
				val += n + " ";
				n = a + b;
			}

			//transform string
			String result = "";
			for(int i = 0 ; i < val.length(); i++) {
				result += val.charAt(i) == ' ' ? ' ' : (char)(val.charAt(i) - 10);
			}

			System.out.println(result);
		}
	}
}
