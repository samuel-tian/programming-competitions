import java.util.*;
import java.io.*;

public class WordSearch
{
	private static final int[][] steps =
	{
		{0, 1}, {1, 0}, {-1, 0}, {0, -1},
		{1, 1}, {1, -1}, {-1, 1}, {-1, -1}
	};

	public static void main(String args[]) throws IOException
	{
		Scanner scan = new Scanner(new File("wordsearch.dat"));
		int t = scan.nextInt();

		while (t-- > 0)
		{
			int n = scan.nextInt();
			int m = scan.nextInt();
			int w = scan.nextInt();

			scan.nextLine();

			char[][] grid = new char[n][m];
			for (int i = 0; i < n; ++i)
			{
				String line = scan.nextLine().replaceAll(" ", "");
				grid[i] = line.toCharArray();
			}

			for (int i = 0; i < w; ++i)
			{
				String word = scan.next();
				if (find(grid, word))
				{
					System.out.print(1);
				}
				else
				{
					System.out.print(0);
				}
			}
			System.out.println();
		}
	}

	public static boolean find(char[][] grid, String word)
	{
		for (int i = 0; i < grid.length; ++i)
		{
			for (int j = 0; j < grid[i].length; ++j)
			{
				for (int k = 0; k < steps.length; ++k)
				{
					int vR = steps[k][0];
					int vC = steps[k][1];

					if (find(grid, word, i, j, vR, vC))
					{
						return true;
					}
				}
			}
		}

		return false;
	}

	public static boolean find(char[][] grid, String word, int i, int j, int vR, int vC)
	{
		int index = 0;

		while (index < word.length())
		{
			if (grid[i][j] != word.charAt(index))
			{
				return false;
			}
			
			i += vR;
			j += vC;

			i = (i + grid.length) % grid.length;
			j = (j + grid[0].length) % grid[0].length;

			++index;
		}

		return true;
	}
}
