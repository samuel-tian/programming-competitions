/*
UIL 2017 - Owen Solution - Neelam
District

Sample input:
56290
4371
802

Sample output:
56290
||o|o
oo|o|
=====
|ooo|
o|ooo
oo|oo
ooooo
ooo|o

4371
oo|o
||o|
====
oooo
ooo|
oo|o
o|oo
|ooo

802
|oo
o||
===
o|o
ooo
oo|
|oo
ooo

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
import static java.lang.Math.*;
class Neelam
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("neelam.dat"));
		while(f.hasNext())
		{
			String num = f.next();
			char[][]grid = {{'o','o','o','o','o'},
			                {'o','o','o','o','o'},
			                {'=','=','=','=','='},
			                {'o','o','o','o','o'},
			                {'o','o','o','o','o'},
			                {'o','o','o','o','o'},
			                {'o','o','o','o','o'},
			                {'o','o','o','o','o'}};
			for(int x=0;x<num.length();x++)
				switch(num.charAt(x))
				{
					case '0':grid[1][x]='|';grid[3][x]='|';break;
					case '1':grid[1][x]='|';grid[4][x]='|';break;
					case '2':grid[1][x]='|';grid[5][x]='|';break;
					case '3':grid[1][x]='|';grid[6][x]='|';break;
					case '4':grid[1][x]='|';grid[7][x]='|';break;
					case '5':grid[0][x]='|';grid[3][x]='|';break;
					case '6':grid[0][x]='|';grid[4][x]='|';break;
					case '7':grid[0][x]='|';grid[5][x]='|';break;
					case '8':grid[0][x]='|';grid[6][x]='|';break;
					case '9':grid[0][x]='|';grid[7][x]='|';break;
				}
				out.println(num);
				for(int r=0;r<grid.length;r++){
					for(int c=0;c<num.length();c++)
						out.print(grid[r][c]);
					out.println();
					
				}
				out.println();
		}
	}
}
/*
Test data
56290
4371
802
9999
3
2000
87654


Test output
56290
||o|o
oo|o|
=====
|ooo|
o|ooo
oo|oo
ooooo
ooo|o

4371
oo|o
||o|
====
oooo
ooo|
oo|o
o|oo
|ooo

802
|oo
o||
===
o|o
ooo
oo|
|oo
ooo

9999
||||
oooo
====
oooo
oooo
oooo
oooo
||||

3
o
|
=
o
o
o
|
o

2000
oooo
||||
====
o|||
oooo
|ooo
oooo
oooo

87654
||||o
oooo|
=====
ooo|o
oo|oo
o|ooo
|oooo
oooo|

*/