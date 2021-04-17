import java.util.*;
import java.io.*;
import java.awt.Point;

public class Mountain
{
	private static int[][] steps =
	{
		{0, 1}, {1, 0}, {-1, 0}, {0, -1}
	};

	public static void main(String[] args) throws IOException
	{
		Scanner scan = new Scanner(new File("mountain.dat"));

		int t = scan.nextInt();

		while (t-- > 0)
		{
			int n = scan.nextInt();

			int[][] grid = new int[n][n];
			int max = 0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					grid[i][j] = scan.nextInt();
					max = Math.max(max, grid[i][j]);
				}
			}

			System.out.println(bfs(grid, max) ? "YES" : "NO");
		}

		scan.close();
	}

	private static boolean isValid(int[][] grid, int row, int col)
	{
		return row >= 0 && col >= 0 && row < grid.length && col < grid[0].length;
	}

	private static boolean bfs(int[][] grid, int max)
	{
		Queue<Point> frontier = new LinkedList<Point>();
		Set<Point> visited = new HashSet<Point>();

		frontier.add(new Point(0, 0));
		visited.add(new Point(0, 0));

		while (!frontier.isEmpty())
		{
			Point p = frontier.poll();

			int value = grid[p.x][p.y];
			if (value == max)
			{
				return true;
			}

			for (int[] step : steps)
			{
				int r = p.x + step[0];
				int c = p.y + step[1];

				if (isValid(grid, r, c) && !visited.contains(new Point(r, c)))
				{
					boolean toPush = false;
					int nextValue = grid[r][c];
					if (value - nextValue >= -1 && value - nextValue <= 2)
					{
						toPush = true;
					}

					if (toPush)
					{
						frontier.add(new Point(r, c));
							visited.add(new Point(r, c));	
					}
				}
			}
		}


		return false;
	}
}
