/*
UIL 2017 - Owen Solution
Invitational A
Geming - integer complement values

In a recent computer science class lesson on integers and their opposite values, Geming has learned a new
concept called the complement. He is a bit confused with this term because he learned one definition
of it in geometry, but now is being taught a new definition, which is this:

The complement of any integer value is its opposite, minus one.  

For example, the complement of zero is -1. The complement of 1 is -2. The complement of -11 is 10, and so on.

Help Geming galvanize his understanding of this new concept by writing a program to input
any integer value in the range, -10000...10000, and output its complement value.

Input: Several integer values, each on one line.

Output: The original value and its complement, separated by a single space, each pair of values on one line.

Sample input:
0
1
-11

Sample output:
0 -1
1 -2
-11 10


*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Geming
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("geming.dat"));
		while(f.hasNext()){
			int N = f.nextInt();
			out.println(N+" "+~N);		
		}
		f.close();
	}
}
/*
Test data
0
1
-11
25
-456
1000
-9999
10000


Test output
0 -1
1 -2
-11 10
25 -26
-456 455
1000 -1001
-9999 9998
10000 -10001

*/