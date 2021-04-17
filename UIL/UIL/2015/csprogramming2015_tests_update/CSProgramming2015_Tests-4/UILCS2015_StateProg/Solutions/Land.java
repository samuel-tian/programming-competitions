import java.util.*;
import java.io.*;
import java.awt.Point;

public class Land
{

	public static int[][] steps =
	{
		{0, 1}, {-1, 0}, {1, 0}, {0, -1}
	};

	public static void main(String args[]) throws IOException
	{
		Scanner scan = new Scanner(new File("land.dat"));
		int t = scan.nextInt();

		while (t-- > 0)
		{
			int n = scan.nextInt();
			int m = scan.nextInt();

			int dry = 0;
			Map<Integer, Integer> waterMap = new TreeMap<Integer, Integer>();
			int[][] grid = new int[n][m];

			int row = -1, col = -1;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					grid[i][j] = scan.nextInt();

					if (grid[i][j] == 0)
					{
						++dry;
						row = i;
						col = j;
					}

					if (!waterMap.containsKey(grid[i][j]))
					{
						waterMap.put(grid[i][j], 0);
					}
					waterMap.put(grid[i][j], waterMap.get(grid[i][j]) + 1);
				}
			}

			List<Integer> water = new ArrayList<Integer>(waterMap.size());
			for (Integer waterDays : waterMap.keySet())
			{
				water.add(waterDays);

				if (water.size() > 1)
				{
					waterMap.put(waterDays, waterMap.get(waterDays) + waterMap.get(water.get(water.size() - 2)));
				}
			}

			int hi = water.size() - 1;
			int lo = 0;
			int mid, best = hi;

			while (lo <= hi)
			{
				mid = lo + (hi - lo) / 2;

				if (success(grid, row, col, water.get(mid), waterMap.get(water.get(mid))))
				{
					best = mid;
					hi = mid - 1;
				}
				else
				{
					lo = mid + 1;
				}
			}
			System.out.println(water.get(best));
		}
	}

	public static boolean success(int[][] grid, int i, int j, int daysPassed, int dryPieces)
	{
		Set<Integer> visited = new HashSet<Integer>();
		Stack<Integer> q = new Stack<Integer>();

		int index = i * grid[0].length + j;

		q.add(index);
		visited.add(index);

		while (!q.isEmpty())
		{
			int p = q.pop();
			int r = p / grid[0].length;
			int c = p % grid[0].length;

			for (int k = 0; k < 4; ++k)
			{
				int row = r + steps[k][0];
				int col = c + steps[k][1];

				if (row >= 0 && col >= 0 && row < grid.length && col < grid[0].length)
				{
					int newIndex = row * grid[0].length + col;
					if (grid[row][col] <= daysPassed && !visited.contains(newIndex))
					{
						q.add(newIndex);
						visited.add(newIndex);
					}
				}
			}
		}

		return visited.size() == dryPieces;
	}
}
