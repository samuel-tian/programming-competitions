import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class thankyou {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner file = new Scanner(new File("thankyou.dat"));
		int cases = file.nextInt();
		file.nextLine();
		while(cases-->0)
		{
			System.out.println("Thank You "+file.nextLine());
		}

	}

}
