import java.util.*;
import java.io.*;

public class Square
{
	public static void main(String args[]) throws IOException
	{
		Scanner scan = new Scanner(new File("square.dat"));

		int t = scan.nextInt();

		while (t-- > 0)
		{
			int n = scan.nextInt();
			int m = scan.nextInt();

			char[][] grid = new char[n][m];
			for (int i = 0; i < n; ++i)
			{
				String line = scan.next();
				grid[i] = line.toCharArray();
			}

			int maxSquareSize = Math.min(n, m);
			int squareCount = 0;

			for (int s = 1; s <= maxSquareSize; ++s)
			{
				for (int i = 0; i < n; ++i)
				{
					for (int j = 0; j < m; ++j)
					{
						if (isSquare(grid, i, j, s, 'x'))
						{
							++squareCount;
						}
					}
				}
			}

			System.out.println(squareCount);
		}

		scan.close();
	}

	public static boolean isSquare(char[][] grid, int row, int col, int s, char filled)
	{
		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j < s; ++j)
			{
				int r = row + i;
				int c = col + j;

				if (!isValid(grid.length, grid[j].length, r, c) || grid[r][c] != filled)
				{
					return false;
				}
			}
		}

		return true;
	}

	public static boolean isValid(int n, int m, int i, int j)
	{
		return i >= 0 && j >= 0 && i < n && j < m;
	}
}