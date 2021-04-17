import java.io.*;
import java.util.*;

public class Bishop
{

	public static int[][] steps =
	{
		{1, 1}, {-1, 1}, {1, -1}, {-1, -1}
	};

	public static boolean isValid(int r, int c, int rows, int cols)
	{
		return r >= 0 && c >= 0 && r < rows && c < cols;
	}

	public static void fill(int r, int c, boolean[][] grid)
	{
		for (int i = 0; i < steps.length; ++i)
		{
			int row = r;
			int col = c;

			while (isValid(row, col, grid.length, grid[0].length))
			{
				grid[row][col] = true;
				row += steps[i][0];
				col += steps[i][1];
			}
		}
	}

	public static void main(String args[]) throws IOException
	{
		Scanner scan = new Scanner(new File("bishop.dat"));

		int t = scan.nextInt();

		while (t-- > 0)
		{
			int n = scan.nextInt();
			int m = scan.nextInt();
			int k = scan.nextInt();

			boolean[][] grid = new boolean[n][m];

			for (int i = 0; i < k; ++i)
			{
				fill(scan.nextInt(), scan.nextInt(), grid);
			}

			int count = 0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (!grid[i][j])
					{
						++count;
					}
				}
			}

			System.out.println(count);
		}

		scan.close();
	}
}