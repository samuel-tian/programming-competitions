/*
UIL 2017 - Owen Solution - Ralph
District

Data storage limits have always been fascinating to Ralph and he wanted to know if there was a way
to test whether or not a number could be "morphed" into the largest possible value to fit into a particular data type.
He knew that the maximum value a 16-bit signed value was 2^15-1, or 32767, and wanted to test his theory.
He needs help to write a program to do this, given any five-digit value greater than 9999 and less than 100,000.

For example, is there a way to maximize the value 12345 by rearranging the digits to find the largest possible value
that would fit in a 16-bit signed integer memory without exceeding the maximum value.
He worked out possible combinations and decided that 32541 was the best combination that
represented the largest possible value without exceeding the limit.

Input: Several five-digit integers N, each within the range 9999<N<100,000.
Output: The largest possible value made up of the five digits in the given integer, or
a message that indicates that any combination exceeds the maximum value.

Sample input:
12345
32677
33445

Sample output:
32541
32767
EXCEEDS MAX VALUE

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Ralph
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("ralph.dat"));
		Scanner k = new Scanner(in);
		while(f.hasNext())
		{
			String s = f.next();
			
			int big = Integer.parseInt(s);
			char[]cc = s.toCharArray();
			for(int a=0;a<5;a++)
			for(int b=0;b<5;b++)
			for(int c=0;c<5;c++)
			for(int d=0;d<5;d++)
			for(int e=0;e<5;e++)
				if(a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e)
				{
					s = ""+cc[a]+cc[b]+cc[c]+cc[d]+cc[e];
					int num = Integer.parseInt(s);
					if(num<=32767&&(big>32767||
						num>big))
						big = num;
				}
			out.println(big<=32767?big:"EXCEEDS MAX VALUE");
		}
		f.close();
	}
}
/*
Test data
12345
32677
33445
10503
32767
32684
33405
67405
60405
99939
99929
21812
95842
98765

Test output
32541
32767
EXCEEDS MAX VALUE
31500
32767
32684
30543
7654
6540
EXCEEDS MAX VALUE
29999
28211
29854
EXCEEDS MAX VALUE

*/