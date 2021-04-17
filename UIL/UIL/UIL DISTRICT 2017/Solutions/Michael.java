/*
UIL 2017 - Owen Solution
District

Sample input:
5 A 2 5 C 5 7 B 7 6 C 8 1 A 4 3
6 A 3 7 B 3 7 C 4 7 B 5 5 C 6 5 B 5 6
6 A 4 4 C 6 2 B 4 6 B 7 3 C 8 4 A 6 4
3 A 5 5 B 5 5 C 5 5
Sample output:
22
16
21
11

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Michael
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("michael.dat"));
		Scanner k = new Scanner(in);
		while(f.hasNext())
		{
			int n = f.nextInt();
			String s = f.nextLine();
			args = s.trim().split(" ");
			char [][] grid = new char[9][9];
//			for(int r=8;r>=1;r--){
//				for(int c=1;c<9;c++)
//					out.print(grid[r][c]!=0?grid[r][c]:'.');
//				out.println();
//			}
			int sum=0;
			for(int x=0;x<n;x++)
			{
				
				int X = Integer.parseInt(args[x*3+2]);
				int Y = Integer.parseInt(args[x*3+1]);
//				out.print(args[x*3]+" row "+X + " col " + Y);
				switch(args[x*3])
				{
					case "A":grid[X][Y]='R';
							 grid[X-1][Y]='A';
							 grid[X-2][Y]='A';
							 grid[X-2][Y+1]='A';
							 grid[X-2][Y+2]='A';
							 break;
					case "B":grid[X][Y]='R';
							 grid[X-1][Y]='B';
							 grid[X-2][Y]='B';
							 grid[X][Y+1]='B';
							 grid[X-1][Y+1]='B';
							 break;
					case "C":grid[X][Y]='R';
							 grid[X+1][Y]='C';
							 grid[X][Y-1]='C';
							 grid[X][Y-2]='C';
							 grid[X][Y-3]='C';
							 break;
				}
//			out.println();
			}
			for(int r=8;r>=1;r--){
				for(int c=1;c<9;c++){
//					out.print(grid[r][c]!=0?grid[r][c]:'.');
					if(grid[r][c]!=0)
						sum++;
				}
//				out.println();
			}
			
			
//			k.nextLine();
		out.println(sum);
		
		}
		f.close();
	}
}
/*
Test data
5 A 2 5 C 5 7 B 7 6 C 8 1 A 4 3
6 A 3 7 B 3 7 C 4 7 B 5 5 C 6 5 B 5 6
6 A 4 4 C 6 2 B 4 6 B 7 3 C 8 4 A 6 4
3 A 5 5 B 5 5 C 5 5
4 A 4 4 A 6 3 B 3 3 C 7 3
4 B 4 6 B 5 6 A 6 4 C 7 3
5 A 1 3 B 1 8 C 8 1 B 7 8 A 4 4
5 A 1 3 A 2 4 A 3 5 C 8 1 C 7 2
4 B 1 8 C 8 1 A 6 3 B 2 7
6 A 4 4 B 1 3 C 4 7 C 5 3 B 2 6 A 5 4
8 A 2 8 B 2 8 C 8 1 B 7 3 C 6 2 A 3 4 B 3 4 C 4 3

Test output
22
16
21
11
15
17
25
24
16
24
26
*/