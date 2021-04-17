import java.util.Scanner;
import java.io.File;
import java.util.LinkedList;
import java.util.List;


public class Mnemonic
{
	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(new File("mnemonic.dat"));
		
		String[] planets = fin.nextLine().split("\\s");
		
		int n = fin.nextInt();
		fin.nextLine();

		for (int i = 0; i < n; i++) {
			String[] mnemonic = fin.nextLine().split("\\s");
						
			for (String word : mnemonic) {
				for (String name : planets) {
					if (name.toLowerCase().startsWith(word.substring(0, 1))) {
						System.out.print(name + " ");
						break;
					}
				}
			}
			System.out.println("");
		}
		
		fin.close();
	}
}