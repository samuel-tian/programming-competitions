/*
UIL 2017 - Edward
Region

Edward has found a board game similar to Go which uses Xs and Os on an 8X8 checker/chess style board. He wants to write a program to simulate the game and needs help with one part of the AI. Given a situation at some point in the game, he wants to know if certain pieces have "captured" other pieces.
For an X piece to capture an O piece, it must be adjacent to it, and have another X on the other side of the O, vertically or horizontally, but not diagonally, also adjacent to it.
If an O is on the edge, it cannot be captured.

For example, in the board shown below, the O at position (6,3) is captured by the Xs at positions (5,3) and (6,3).
The same is true for the O at position (6,6), captured by the Xs at positions (6,5) and (6,7).
However, the two Os in the bottom right corner at positions (1,8) and (2,8) are not captured since they are on the edge, even though they are surrounded by X pieces.

--------
--X-----
--O-XOX-
--X-----
--------
-------X
------XO
------XO

What Edward needs to know is when the position of an X position is indicated, what O piece, if any, is it helping to capture? For example, if the X piece at position (7,3) is indicated, the answer would be the position of the O piece it is helping to capture, which would be (6,3).
If the X piece at position (1,7) is mentioned, there would be no O piece it is helping to capture, so the answer would be NONE.

Since this step is just the starting point in the overall AI of the game, Edward will only use data where at most one O is captured by any X piece.

Input: An initial value N, indicating N data sets to follow. Each data set consists of a row of O piece coordinates, a row of X piece coordinates, another integer P, followed by P ordered pairs, indicating the X pieces to query.
The two rows for O and X pieces begin with an integer indicating how many pieces are to be place on the board, followed by that many ordered pairs for each piece.

Output: The coordinate of the O piece that the indicated X piece is helping to capture, or the phrase "NONE" if there is no capture. It is guaranteed that each X piece will help capture at most one O piece.
A single blank line will follow each output.

Sample Input: 
2
4 1 8 2 8 6 3 6 6
7 1 7 2 7 3 8 5 3 7 3 6 5 6 7
5
7 3
6 5
5 3
3 8
1 7
4 1 1 2 2 2 6 1 7
9 2 1 1 2 3 2 1 5 2 5 2 3 1 6 2 7 1 8
6
3 2
2 1
1 2
1 5
1 8
2 7

Sample Output:
7,3 ==> (6,3)
6,5 ==> (6,6)
5,3 ==> (6,3)
3,8 ==> NONE
1,7 ==> NONE

3,2 ==> (2,2)
2,1 ==> (2,2)
1,2 ==> (2,2)
1,5 ==> NONE
1,8 ==> (1,7)
2,7 ==> (2,6)
 
*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Edward
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("edward.dat"));
		int N = f.nextInt();
		while(N-->0)
		{
			char grid [][] = new char[9][9];
			int O = f.nextInt();
			for(int x=0;x<O;x++)
				grid[f.nextInt()][f.nextInt()]='O';
			int X = f.nextInt();
			for(int x=0;x<X;x++)
				grid[f.nextInt()][f.nextInt()]='X';
			//output grid
//			outGrid(grid);
			int n = f.nextInt();
			for(int a=0;a<n;a++){
				int R=f.nextInt();
				int C=f.nextInt();
				out.print("("+R+","+C+") ==> ");
				//look north
				if(R<=6&&grid[R+1][C]=='O'&&grid[R+2][C]=='X')
					out.println("("+(R+1)+","+C+")");
//					out.println("north "+(R+1)+","+C);
				else
				//look south
				if(R>=3&&grid[R-1][C]=='O'&&grid[R-2][C]=='X')
					out.println("("+(R-1)+","+C+")");
//					out.println("south "+(R-1)+","+C);
				else
				//look east
				if(C<=6&&grid[R][C+1]=='O'&&grid[R][C+2]=='X')
					out.println("("+R+","+(C+1)+")");
//					out.println("east "+R+","+(C+1));
				else
				//look west
				if(C>=3&&grid[R][C-1]=='O'&&grid[R][C-2]=='X')
					out.println("("+R+","+(C-1)+")");
//					out.println("west "+R+","+(C-1));
				else
					out.println("NONE");
			}
		out.println();
		}
	}
	static void outGrid(char[][]g)
	{
		for(int r=8;r>0;r--)
		{
			for(int c=1;c<=8;c++)
				out.print(g[r][c]!=0?g[r][c]:'-');
			out.println();
		}
		out.println();
	}
}
/*
Test input:
3
4 1 8 2 8 6 3 6 6
7 1 7 2 7 3 8 5 3 7 3 6 5 6 7
5
7 3
6 5
5 3
3 8
1 7
4 1 1 2 2 2 6 1 7
9 2 1 1 2 3 2 1 5 2 5 2 3 1 6 2 7 1 8
6
3 2
2 1
1 2
1 5
1 8
2 7
8 1 8 3 6 7 2 6 3 5 4 4 5 6 7 4 8
13 7 1 6 1 6 4 5 3 4 4 5 5 6 6 2 6 5 7 4 7 1 7 6 8 2 8
9
7 1 
5 3 
6 1 
5 5 
6 6 
6 8 
2 8 
1 7 
6 4

Output
(7,3) ==> (6,3)
(6,5) ==> (6,6)
(5,3) ==> (6,3)
(3,8) ==> NONE
(1,7) ==> NONE

(3,2) ==> (2,2)
(2,1) ==> (2,2)
(1,2) ==> (2,2)
(1,5) ==> NONE
(1,8) ==> (1,7)
(2,7) ==> (2,6)

(7,1) ==> NONE
(5,3) ==> (5,4)
(6,1) ==> NONE
(5,5) ==> (5,4)
(6,6) ==> (6,7)
(6,8) ==> (6,7)
(2,8) ==> NONE
(1,7) ==> NONE
(6,4) ==> (5,4)

*/