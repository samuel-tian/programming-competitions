import java.util.*;
import java.io.*;

public class Fibonacci
{
	public static void main(String[] args) throws IOException
	{
		Scanner scan = new Scanner(new File("fibonacci.dat"));
		int t = scan.nextInt();

		while (t-- > 0)
		{
			int n = scan.nextInt();

			if (n == 0 || n == 1)
			{
				System.out.println(0);
				continue;
			}

			long[] values = new long[n + 1];
			values[0] = values[1] = 1;

			for (int i = 2; i <= n; ++i)
			{
				values[i] = 1L + values[i - 1] + values[i - 2];
			}

			System.out.println(values[n] - n - 1);
		}	
	}
}
