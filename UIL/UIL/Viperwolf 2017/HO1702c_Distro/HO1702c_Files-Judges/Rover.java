import java.util.Scanner;
import java.io.File;
import java.awt.Point;
import java.util.Stack;


public class Rover
{
	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(new File("rover.dat"));
		
		double up = 10 * Math.tan(Math.toRadians(33));
		double down = 10 * Math.tan(Math.toRadians(42));
				
		int rows = fin.nextInt();
		int cols = fin.nextInt();

		int r = fin.nextInt();
		int c = fin.nextInt();
		
		double[][] topo = new double[rows + 2][cols + 2];
		boolean[][] reachable = new boolean[rows + 2][cols + 2];
		
		for (int row = 0; row < rows + 2; row++) {
			topo[row][    0   ] = Double.MAX_VALUE;
			topo[row][cols + 1] = Double.MAX_VALUE;
		}
		
		for (int col = 0; col < cols + 2; col++) {
			topo[    0   ][col] = Double.MAX_VALUE;
			topo[rows + 1][col] = Double.MAX_VALUE;
		}
		
		for (int row = 1; row <= rows; row++) {
			for (int col = 1; col <= cols; col++) {
				topo[row][col] = fin.nextDouble();
			}
		}
		
		Stack<Point> locs = new Stack<>();
		locs.push(new Point(c+ 1, r + 1));
				
		while(!locs.isEmpty()) {
			Point loc = locs.pop();
			r = loc.y;
			c = loc.x;
			
			double here = topo[r][c];
			
			Point[] nsew = new Point[] {
				new Point(c, r-1), new Point(c, r+1), new Point(c+1, r), new Point(c-1, r)	
			};
			
			for (Point p : nsew) {
				if (!reachable[p.y][p.x]) {
					double there = topo[p.y][p.x];
					if (here <= there && there - here < up || 
					    here > there && here - there < down) {
						reachable[p.y][p.x] = true;
						locs.push(p);
					}
				}
			}
		}
		
		for (int row = 1; row <= rows; row++) {
			for (int col = 1; col <= cols; col++) {
				System.out.print(reachable[row][col] ? "#" : "-");
			}
			System.out.println();
		}
		
		fin.close();
	}
}