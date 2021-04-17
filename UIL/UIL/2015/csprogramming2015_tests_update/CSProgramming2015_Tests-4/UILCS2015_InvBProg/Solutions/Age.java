import java.util.Scanner;
import java.io.*;

public class Age
{
	public static void main(String[] args) throws IOException
	{
		Scanner scan = new Scanner(new File("age.dat"));
		int T = scan.nextInt();

		while (T-- > 0)
		{
			int young = scan.nextInt();
			int old = scan.nextInt();
			int multiple = scan.nextInt();

			int difference = old - young;
			boolean success = false;

			for (int i = 1, j = difference + 1; i * multiple <= j; ++i, ++j)
			{
				if (i * multiple == j)
				{
					System.out.println(i + " " + j);
					success = true;
					break;
				}
			}

			if (!success)
			{
				System.out.println("NEVER");
			}
		}

		scan.close();
	}
}
