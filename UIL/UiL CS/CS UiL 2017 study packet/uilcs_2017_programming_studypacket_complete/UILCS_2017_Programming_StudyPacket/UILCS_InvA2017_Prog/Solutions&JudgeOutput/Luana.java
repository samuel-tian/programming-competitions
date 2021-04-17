/*
UIL 2017 - Owen Solution
Invitational A
Luana has just learned about a biological simulation of
how cells migh evolve given a certain set of rules on how they are born, survive, 
and die in several life cycle generations.  
In this study, a 10 by 10 grid is used, like the one shown below, to indicate the beginning
generation. The top left cell is in position (1,1), and the one right below it is
in position (2,1). Every cell has at most eight neighboring cells.

For this exercise, the grid shown below will be the starting generation 
each time a new set of evolution rules is applied.

Here is an example of a set of rules. There 2 ways for a dead cell to be reborn, and
that is when it is surrounded by exactly 2 or 4 neighboring cells, otherwise it stays dead. 
There are 2 ways for a living cell to survive, and that is has 3 or 4 living neighbors,
otherwise it dies. The research is to check the status of a particular cell, (5,2) for example,
at each generation for a number of generation cycles, let's say 4. 

In the grids shown below, a * indicates a living cell, and a - a dead cell. If the right number of
neighboring cells surrounds a dead cell, it will be reborn, or can survive to the next generation. 
If not enough cells surround a living cell, it will die.

The data set for this situation would be: 2 2 4 2 3 4 4 5 2.
The result will be DADAA, which means that cell (5,2) is dead to start with, is
reborn after the first generation cycle, dies after the second, is reborn
after the third, and stays alive for the fourth.

Let's look at this sequence carefully.

Sample evolution of cell in location (5,2), reborn when surrounded by 2 or 4 
living cells, surviving when surrounded by 3 or 4 living cells, dying otherwise.

First generation
*---------
*---------
---*------
----*----- 
--*--*---* Cell in (5,2) is currently dead, but is reborn in the 
-*-**--*--  next generation since it is surrounded by 2 living cells
--*-----**
-*-------*
*--------*
---------*
Second generation
-*--------
-*--------
----*-----
--*--*----
-*-**-*-*- Cell in (5,2) is alive, but dies since it is only surrounded 
--**-**-*-  by 2 living cells (needs 3 or 4 living neighbors to survive)
*-*-*--**-
*-*-----**
-*--------
--------*-
Third generation
*-*-------
*-*-------
-***-*----
-*-*****--
---**-**-* Cell in (5,2) is dead, but is reborn in the next generation 
***--**-*-  since it is surrounded by 4 living cells
--*----***
--------*-
*-*----*--
----------
Fourth generation
-*-*------
--***-----
-*-*-***--
*------*--
-*-*----*- Cell in (5,2) is alive, and stays alive in the next generation, 
-***-**--*  surrounded by 3 living cells.
**-*-*-***
--**--***-
-*------*-
-*--------

Input: The initial 10X10 grid as described above, with a value N on the second
line, followed on the next N lines with simulation data sets.  Each data set
consists of an integer B, followed by B integers indicating the number of neighbors
required for a dead cell to be reborn, then an integer S, followed by S integers
indicating the number of neighbors required for survival.  After that is an integer
G, which indicates how many generations to examine, and finally an ordered pair of integers
R and C, indicating the cell location to study.

Output: A string of letters D or A indicating the status of the indicated cell, showing
the initial state, and the state after each generation.

Sample input:
*---------
*---------
---*------
----*-----
--*--*---*
-*-**--*--
--*-----**
-*-------*
*--------*
---------*
2
2 2 4 2 3 4 4 5 2
3 1 2 3 3 1 2 3 2 5 10

Sample output:
DADAA
ADD

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;

class Luana
{
	static Scanner kb = new Scanner(in);
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("luana.dat"));
		boolean [][] grid = new boolean[12][12];
		boolean [][] grid1 = new boolean[12][12];
		boolean [][] grid2 = new boolean[12][12];
		for(int r=1;r<=10;r++)
		{
			String s = f.next();
			for(int c=1;c<=10;c++)
				grid[r][c]=s.charAt(c-1)=='*';
		}
//		outputGrid(grid);
		int N = f.nextInt();
		f.nextLine();
		while(N-->0){
			for(int r=1;r<=10;r++)//reset grid1
			{
				for(int c=1;c<=10;c++)
					grid1[r][c]=grid[r][c];
			}
			String s = f.nextLine();
			Scanner ch = new Scanner(s);
			Set<Integer> birth = new HashSet();
			Set<Integer> survive = new HashSet();
			int n = ch.nextInt();
			for(int x=0;x<n;x++)
				birth.add(ch.nextInt());
			n = ch.nextInt();
			for(int x=0;x<n;x++)
				survive.add(ch.nextInt());
			n = ch.nextInt();
			int r=ch.nextInt();
			int c=ch.nextInt();
//			out.println("start...("+r+","+c+")"+(grid1[r][c]?'A':'D'));
			out.print(grid1[r][c]?'A':'D');
//			kb.nextLine();
			for(int x=0;x<n;x++)
			{
				gen(grid1,grid2,birth,survive,r,c);
				grid1 = grid2;//assign new gen to grid1
				grid2 = new boolean[12][12];//create new grid2
			}
			out.println();
		}
		f.close();
	}
	static void outputGrid(boolean[][]g)
	{
		for(int r=1;r<=10;r++)
		{
			for(int c=1;c<=10;c++)
				out.print(g[r][c]?'*':'-');
			out.println();
		}
	}
	static void gen(boolean[][]g1,boolean[][]g2,Set<Integer>b,Set<Integer>s,int r, int c)
	{
		
//		out.println("birth set = "+b);
//		out.println("survive set = "+s);
		for(int R=1;R<=10;R++)
		{
			for(int C=1;C<=10;C++)
			{
//				out.print("("+R+","+C+")"+(g1[R][C]?'A':'D')+" ==> ");
				int neigh = neighbors(g1,R,C);
//				out.print(neigh+" neighbors ==> ");
				if(g1[R][C]&&s.contains(neigh)||!g1[R][C]&&b.contains(neigh))
					g2[R][C]=true;
//				out.println(g2[R][C]?'A':'D');
			}
		}
//		outputGrid(g2);
//		out.println("....("+r+","+c+")"+(g2[r][c]?'A':'D'));
		out.print(g2[r][c]?'A':'D');
//		kb.nextLine();	
	}
	static int neighbors(boolean[][]g,int r, int c)
	{
		int sum=0;
		if(g[r][c-1])sum++;//w
		if(g[r][c+1])sum++;//e
		if(g[r-1][c])sum++;//n
		if(g[r+1][c])sum++;//s
		if(g[r-1][c-1])sum++;//nw
		if(g[r-1][c+1])sum++;//ne
		if(g[r+1][c-1])sum++;//sw
		if(g[r+1][c+1])sum++;//se
		return sum;
	}
}
/*
Test data
*---------
*---------
---*------
----*-----
--*--*---*
-*-**--*--
--*-----**
-*-------*
*--------*
---------*
8
2 2 4 2 3 4 1 5 2
2 2 4 2 3 4 4 5 2
3 1 2 3 3 1 2 3 2 5 10
2 1 2 2 1 2 3 1 1
2 1 3 2 1 3 1 2 1
2 1 3 2 1 3 3 5 5
2 3 4 2 2 3 2 5 9
2 2 3 2 1 2 5 5 9

Test output
DA
DADAA
ADD
AADD
AA
DDDA
DDD
DAADDA

*/