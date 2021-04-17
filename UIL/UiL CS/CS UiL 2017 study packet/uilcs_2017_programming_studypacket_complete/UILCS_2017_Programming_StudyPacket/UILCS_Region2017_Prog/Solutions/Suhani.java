/*
UIL 2017 - Suhani
Region

In geometry class, Suhani is studying about congruent triangles and has learned that triangles are congruent when all three side lengths of one triangle match in some way the three sides of the other triangle.
For example, a triangle ABC with side lengths 3, 4, and 5 is congruent to another triangle DEF with side lengths of 3, 4 and 5.
Side A matches with side D, B with E, and C with F.
Even if the lengths are listed in a different order, like 3, 4 and 5 for the triangle ABC and then 4, 5 and 3 for DEF, they are still considered congruent.
Side A matches F, B matches D, and C matches E.

If not all three sides match, it is still possible for some of the sides to match, or none at all. 

Suhani wants to be able to take the side lengths of any two triangles and determine how many side lengths match, which could be none, 1, 2, or all 3.

Input: Several sets of data, each set on one line, consisting of six non-negative values, with single space separation.

Output: The number of sides that match between the two triangles.

Sample Input: 
3 4 5 3 4 5
2 3 4 4 3 2
3 4 5 5 2 3
2 3 4 2 3 4.5
2 2 3 3.5 2 2

Sample Output:
3
2
2
2
*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Suhani
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("suhani.dat"));
		while(f.hasNext())
		{
			//array for first triangle lengths A, B, and C
			double []t1 = new double[3];
			//array for second triangle lengths A, B, and C				
			double []t2 = new double[3];
			//array for matches
			boolean [] tm = new boolean[3]; 
			t1[0] = f.nextDouble();
			t1[1] = f.nextDouble();
			t1[2] = f.nextDouble();
			t2[0] = f.nextDouble();
			t2[1] = f.nextDouble();
			t2[2] = f.nextDouble();
			int con = 0;
			for(int r=0;r<t1.length;r++)
			{
				for(int c=0;c<t2.length;c++)
				//record a match in the boolean array
				if(t1[r]==t2[c])
					tm[c]=true;
			}
			//count the number of matches in the boolean array
			for(int x=0;x<3;x++)
				if(tm[x])
					con++;
			out.println(con);	
		}
	}
}
/*
Test input:
3 4 5 3 4 5
2 3 4 4 3 2
3 4 5 5 2 3
2 3 4 2 3 4.5
2 2 3 3.5 2 2
2 2 2 1 2 2.5 
3 4 5 3 4 5
5 7 11 11 7 6
6 8 10 4 6 8
6 8 10 5 7 12
9 12 15 12 9 15

Test Output:
3
3
2
2
2
1 
3
2
2
0
3

*/