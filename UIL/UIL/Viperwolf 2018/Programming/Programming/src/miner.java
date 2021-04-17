import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class miner {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner file = new Scanner(new File("miner.dat"));
		int cases = file.nextInt();
		file.nextLine();
		while(cases-->0)
		{
			String a = file.nextLine();
			System.out.println(a.substring(a.indexOf("p:")+2,a.lastIndexOf(":p")));
			
		}

	}
}
