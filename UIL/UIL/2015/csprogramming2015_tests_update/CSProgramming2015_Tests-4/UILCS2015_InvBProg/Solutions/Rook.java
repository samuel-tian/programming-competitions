import java.util.*;
import java.io.*;

public class Rook
{
	public static void main(String args[]) throws IOException
	{
		Scanner scan = new Scanner(new File("rook.dat"));

		int t = scan.nextInt();

		while (t-- > 0)
		{
			int n = scan.nextInt();
			int m = scan.nextInt();
			int k = scan.nextInt();

			boolean[] usedRows = new boolean[n];
			boolean[] usedCols = new boolean[m];

			int rows = n;
			int cols = m;

			for (int i = 0; i < k; ++i)
			{
				int row = scan.nextInt();
				int col = scan.nextInt();

				if (!usedRows[row])
				{
					--rows;
				}

				if (!usedCols[col])
				{
					--cols;
				}

				usedRows[row] = true;
				usedCols[col] = true;
			}

			System.out.println(rows * cols);
		}

		scan.close();
	}
}