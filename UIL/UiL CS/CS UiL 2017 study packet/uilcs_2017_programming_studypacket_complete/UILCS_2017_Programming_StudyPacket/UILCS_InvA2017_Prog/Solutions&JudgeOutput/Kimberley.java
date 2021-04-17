/*
UIL 2017 - Owen Solution
Invitational A

Kimberley loves watching birds, especially the large flocks that move together
in flight so gracefully. She has recently run across a theory study of how these flocks
move, and needs your help in simulating a small part of that study.

Using a single row of birds that always fly from left to right, she wants to see
how some simple rules will determine the position of each bird in the row after
a certain time stage as the birds fly. 

The rules of the simulation are:
1.  If at the beginning of any stage change, the left most space in the row is empty and the right most space is occupied by a bird, that bird leaves the right most space empty and moves to the left most space for the next stage.
2.  A bird stays in place if the space to the right of it is occupied.
3.  A bird moves one place to the right if that space is empty.
4.  A bird moves at most one time during a stage.

For example, the following diagram represents a flock of birds in three stages,
moving according to the rules listed below. 

From stage 1 to 2, the birds in positions 1, 4, and 6 move. All others remain.
From stage 2 to 3, the bird in space 10 falls back to position 1, and then the birds in 3, 5 and 9 all move.

Position | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|
--------------------------------------------------
Stage 1  | * |   | * | * |   | * |   | * | * | * | 
Stage 2  |   | * | * |   | * |   | * | * | * | * |
Stage 3  | * | * |   | * |   | * | * | * |   | * |
--------------------------------------------------

Input: Several sets of data, each data set consisting of a row of integers with single space separation.
The first integer represents the number of spaces to be used in the row. The next integer N
indicates how many birds are in the row, with the next N values indicating their positions in the row.
The final integer represents the number of stages to be considered for the simulation.

Output: After the final stage of each data set is completed, report the positions of all of the birds as a row of integers with single space separation.

Sample input:
9 3 1 3 5 2
12 6 1 3 5 7 10 11 4
10 7 1 3 4 6 8 9 10 3 (this data set matches the example described above)

Sample output:
2 4 6
2 4 6 8 10 12
1 2 4 6 7 8 10
*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;

class Kimberley
{
//	static Scanner kb = new Scanner(in);
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("kimberley.dat"));
		while(f.hasNext()){
			String s = f.nextLine();
			Scanner ff = new Scanner(s);
			int n = ff.nextInt();
			boolean [] row = new boolean[n+1];
			n = ff.nextInt();
			while(n-->0)
				row[ff.nextInt()]=true;
			n=ff.nextInt();
			while(n-->1)
			{
				stage(row);
			}
			for(int x=1;x<row.length;x++)
				if(row[x])
					out.print(x+" ");
			out.println();
		}
		f.close();
	}
	static void stage(boolean [] row)
	{
//		out.println("stage");
		//Rule 1 - if leftmost space (first position) is empty 
		//and right most space (last position)contains a bird,
		//the right most bird moves to the left most space
//		out.println("Rule 1");
		boolean rule1=false;
		if(row[row.length-1]&&!row[1]){
			row[row.length-1]=false;
			row[1]=true;
//			out.println("YES");
			rule1=true;
		}
//		out.println("Rule 4");
		for(int x=1;x<row.length-1;x++){
			if(x==1&&rule1)
				continue;
			if(row[x]&&!row[x+1]){
				row[x]=false;
				row[x+1]=true;
//				out.println("bird moves from "+x+" to "+(x+1));
				x++;
			}
		}
	}
}
/*
Test data
9 3 1 3 5 2
12 6 1 3 5 7 10 11 4
10 7 1 3 4 6 8 9 10 3
8 4 4 5 6 7 4
10 4 1 4 8 10 5
20 9 2 5 8 9 10 11 14 17 20 5
10 6 3 4 6 7 9 10 5
10 4 7 8 9 10 7

Test output
2 4 6
2 4 6 8 10 12
1 2 4 6 7 8 10
2 4 6 8
1 3 5 8
1 4 6 7 9 11 13 15 18
2 3 5 7 9 10
2 4 6 10

*/