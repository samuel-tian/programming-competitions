import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class cards {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner file = new Scanner(new File("cards.dat"));
		int cases = file.nextInt();
		file.nextLine();
		while(cases-->0)
		{
			System.out.println(52-file.nextLine().replaceAll("[0-9]", "").length());
		}

	}
}
