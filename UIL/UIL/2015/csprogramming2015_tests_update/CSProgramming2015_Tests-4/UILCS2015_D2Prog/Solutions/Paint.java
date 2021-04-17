import java.util.*;
import java.io.*;

public class Paint
{
	public static void main(String args[]) throws IOException
	{
		Scanner scan = new Scanner(new File("paint.dat"));

		int T = scan.nextInt();

		while (T-- > 0)
		{
			int n = scan.nextInt();
			int m = scan.nextInt();

			boolean[][] board = new boolean[n][m];

			for (int i = 0; i < n; ++i)
			{
				String line = scan.next();
				for (int j = 0; j < m; ++j)
				{
					if (line.charAt(j) == 'x')
					{
						board[i][j] = true;
					}
				}
			}

			String folds = scan.next();
			for (int i = 0; i < folds.length(); ++i)
			{
				if (folds.charAt(i) == 'H')
				{
					foldHorizontal(board);
				}
				else
				{
					foldVertical(board);
				}
			}

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (board[i][j])
					{
						System.out.print('x');
					}
					else
					{
						System.out.print('.');
					}
				}
				System.out.println();
			}
		}
	}

	public static void foldHorizontal(boolean[][] grid)
	{
		for (int i = 0; i < grid.length; ++i)
		{
			for (int j = 0; j < grid[i].length; ++j)
			{
				grid[i][j] = grid[i][grid[i].length - j - 1] = grid[i][j] || grid[i][grid[i].length - j - 1];
			}
		}
	}

	public static void foldVertical(boolean[][] grid)
	{
		for (int i = 0; i < grid.length; ++i)
		{
			for (int j = 0; j < grid[i].length; ++j)
			{
				grid[i][j] = grid[grid.length - i - 1][j] = grid[i][j] || grid[grid.length - i - 1][j];
			}
		}
	}
}