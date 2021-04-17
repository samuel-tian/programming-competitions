import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigDecimal;
import java.util.Scanner;

public class area {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner file = new Scanner(new File("area.dat"));
		int cases = file.nextInt();
		file.nextLine();
		while(cases-->0)
		{
			System.out.printf("%.2f\n", file.nextDouble()*file.nextDouble());
		}

	}

}
