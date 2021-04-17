/*
UIL 2017 - Brandon
Region

Brandon was playing around with a program to output square values and decided to display them in either integer format or decimal format depending on the odd/even nature of the value.
See if you can replicate his program.

Input: A series of integer values, all on one line, with single space separation.

Output: The square value of each number, either in integer format, or decimal format, based on the odd or even state of the number, as shown in the sample data and output below.

Sample input:
56 11 -34

Sample output:
3136
121.0
1156

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Brandon
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("brandon.dat"));
		while(f.hasNext())
		{
			int n = f.nextInt();
			double d = Math.pow(n,2);
			if(d%2==0)
				out.println((int)d);
			else
				out.println(d);
		}
	}
}
/*
Test input:
56 11 -34 79 100 73 -9 123

Output
3136
121.0
1156
6241.0
10000
5329.0
81.0
15129.0

*/