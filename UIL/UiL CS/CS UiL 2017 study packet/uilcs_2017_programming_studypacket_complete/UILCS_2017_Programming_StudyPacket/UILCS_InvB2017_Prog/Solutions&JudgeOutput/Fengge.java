/*
UIL 2017 - Owen Solution
Invitational B
In computer science class, Fengge has been learning about creating output box patterns.  He decides to write a program that creates a box pattern that is hollow.  For example, a 5 X 6 box made of stars (“*”) would look like this:
******
******
**  **
******
******

A 9X7 box made of the letter “a” would look like this:
aaaaaaa
aaaaaaa
aa   aa
aa   aa
aa   aa
aa   aa
aa   aa
aaaaaaa
aaaaaaa

Input: Several data sets, each set on one line, consisting of two integers R and C, each greater than 4 and less than 20 in value, and a single character A, with single space separation.

Output: A hollow box with R rows and C columns, with a double edge border filled with the input character A. One blank line follows the box.

Sample input:
5 6 *
9 7 a

Sample output:
******
******
**  **
******
******

aaaaaaa
aaaaaaa
aa   aa
aa   aa
aa   aa
aa   aa
aa   aa
aaaaaaa
aaaaaaa


*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Fengge
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("fengge.dat"));
		while(f.hasNext()){
			int R = f.nextInt();
			int C = f.nextInt();
			char a = f.next().charAt(0);
			for(int r=0;r<R;r++){
				for(int c=0;c<C;c++)
				{
					if((r<2 || r>=R-2 || c<2 || c>=C-2))
						out.print(a);
					else
						out.print(" ");
				}
				out.println();
			}
			out.println();
		}
		
	}
}
/*
Test data
5 6 *
9 7 a
19 19 %
6 5 ^
10 10 &
Test output
******
******
**  **
******
******

aaaaaaa
aaaaaaa
aa   aa
aa   aa
aa   aa
aa   aa
aa   aa
aaaaaaa
aaaaaaa

%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%
%%               %%
%%               %%
%%               %%
%%               %%
%%               %%
%%               %%
%%               %%
%%               %%
%%               %%
%%               %%
%%               %%
%%               %%
%%               %%
%%               %%
%%               %%
%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%

^^^^^
^^^^^
^^ ^^
^^ ^^
^^^^^
^^^^^

&&&&&&&&&&
&&&&&&&&&&
&&      &&
&&      &&
&&      &&
&&      &&
&&      &&
&&      &&
&&&&&&&&&&
&&&&&&&&&&


*/