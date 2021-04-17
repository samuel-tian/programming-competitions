/*
UIL 2017 - Owen Solution
Invitational B

After seeing the simple box pattern Fengge did in class, Nastya, not to be outdone,
decides to do a one-up on him and create something a bit more elaborate, according
to these rules.

Her pattern will be rectangular, simulating a wall of a house, with three values input, A, B, and C. 
The value A represents the thickness of the wall, B the number of columns between the left and right walls,
and C the height of the wall.  The walls will be indicated by the letters I and X. For walls
with a thickness of 2 or less, Is will be used, otherwise Xs will be used for interior columns
between the two Is. Cross letters begin inside each wall, starting at the top of the left wall, with Rs that descend
diagonally until they hit the opposite wall, or the floor.  Likewise, Ls will start at the top of the 
right side wall and descend diagonally until they hit the opposite wall of the floor.
Anytime an R and L occupy the same cell, and S will be used instead.
If an R or L reaches a wall, or the bottom row, then that becomes the last row for the cross letters.

For the input values A = 2, B = 4, and C = 5, the wall pattern is as follows:
IIR  LII
II IL II
IIL  RLL
II    II

The data set 3 10 8 results in:
IXIR        LIXI
IXI R      L IXI
IXI  R    L  IXI
IXI   R  L   IXI
IXI    RL    IXI
IXI   L  R   IXI
IXI  L    R  IXI

The input values 1 5 6 produce:
IR   LI
I R L I
I  S  I
I L R I
IL   RI
I     I


Input: Several data sets, each set on one line, as described above.

Output: A wall cross-section pattern, also as described above.  Each pattern will be
followed by a blank line.

Sample input:
2 4 5
3 10 8
1 5 6

Sample output:
IIR  LII
II RL II
II LR II
IIL  RII
II    II

IXIR        LIXI
IXI R      L IXI
IXI  R    L  IXI
IXI   R  L   IXI
IXI    RL    IXI
IXI    LR    IXI
IXI   L  R   IXI
IXI  L    R  IXI

IR   LI
I R L I
I  S  I
I L R I
IL   RI
I     I

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Nastya
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("nastya.dat"));
		while(f.hasNext())
			{
			int A = f.nextInt();
			int B = f.nextInt();
			int C = f.nextInt();
			int row = C;
			int col = A+A+B;
			char[][]grid=new char[row][col];
			//outside columns get I
			for(int c=0;c<A;c++)
			for(int r=0;r<row;r++)
				if(c==0 || c == A-1)
					grid[r][c] = grid[r][col-c-1] = 'I';
				else
					grid[r][c] = grid[r][col-c-1] = 'X';
			for(int c=A,r=0;r<row&&c<col-A;c++,r++)
				grid[r][c]='R';
			for(int c=col-A-1,r=0;r<row&&c>=A;c--,r++)
				if(grid[r][c]=='R')
					grid[r][c]='S';
				else
					grid[r][c]='L';
			
			//output grid
			for(int r=0;r<row;r++){
				for(int c=0;c<col;c++)
					out.print(grid[r][c]);
				out.println();
			}
			out.println();

		}
		
	}
}
/*
Test data
2 4 5
3 10 8
1 5 6
1 6 6
4 7 4
2 3 3
2 6 4
3 5 3
4 3 5
4 5 5
5 1 3
4 4 4
1 5 5
2 8 6
Test output
IIR  LII
II RL II
II LR II
IIL  RII
II    II

IXIR        LIXI
IXI R      L IXI
IXI  R    L  IXI
IXI   R  L   IXI
IXI    RL    IXI
IXI    LR    IXI
IXI   L  R   IXI
IXI  L    R  IXI

IR   LI
I R L I
I  S  I
I L R I
IL   RI
I     I

IR    LI
I R  L I
I  RL  I
I  LR  I
I L  R I
IL    RI

IXXIR     LIXXI
IXXI R   L IXXI
IXXI  R L  IXXI
IXXI   S   IXXI

IIR LII
II S II
IIL RII

IIR    LII
II R  L II
II  RL  II
II  LR  II

IXIR   LIXI
IXI R L IXI
IXI  S  IXI

IXXIR LIXXI
IXXI S IXXI
IXXIL RIXXI
IXXI   IXXI
IXXI   IXXI

IXXIR   LIXXI
IXXI R L IXXI
IXXI  S  IXXI
IXXI L R IXXI
IXXIL   RIXXI

IXXXISIXXXI
IXXXI IXXXI
IXXXI IXXXI

IXXIR  LIXXI
IXXI RL IXXI
IXXI LR IXXI
IXXIL  RIXXI

IR   LI
I R L I
I  S  I
I L R I
IL   RI

IIR      LII
II R    L II
II  R  L  II
II   RL   II
II   LR   II
II  L  R  II

*/