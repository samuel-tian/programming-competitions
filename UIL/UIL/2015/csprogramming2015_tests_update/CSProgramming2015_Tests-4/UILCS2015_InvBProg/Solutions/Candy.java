import java.util.Scanner;
import java.io.*;

public class Candy
{
	public static void main(String args[]) throws IOException
	{
		Scanner scan = new Scanner(new File("candy.dat"));

		int T = scan.nextInt();

		while (T-- > 0)
		{
			int n = scan.nextInt();
			int lcm = scan.nextInt();

			for (int i = 0; i < n - 1; ++i)
			{
				int groupSize = scan.nextInt();
				int gcd = gcd(lcm, groupSize);

				lcm *= groupSize;
				lcm /= gcd;
			}

			System.out.println(lcm);
		}

		scan.close();
	}

	public static int gcd(int a, int b)
	{
		return (b == 0) ? a : gcd(b, a % b);
	}
}
