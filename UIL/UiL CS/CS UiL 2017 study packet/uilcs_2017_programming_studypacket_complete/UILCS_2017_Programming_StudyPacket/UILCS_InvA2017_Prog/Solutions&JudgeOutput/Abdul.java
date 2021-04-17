/*
UIL 2017 - Owen Solution
Invitational A
Abdul - Accumulation loop

In his fascination with math patterns, Abdul has discovered an interesting phenomenon
when adding up odd numbered values.  Help him by writing a program for his research project.

Write a program to input a positive integer N (2 < N <= 100) and output 
the sum of all the odd integers from 1 up to, but not including, twice that number. For example, 
if N is 5, you would add the values 1, 3, 5, 7 and 9, which makes 25.

Input: Several integers, each on one line.

Output: The sum of all odd values from 1 up to 2N.

Sample input:
5
11
16

Sample output:
25
121
256

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Abdul
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("abdul.dat"));
		while(f.hasNext()){
			int N = f.nextInt();
			int sum = 0;
			for(int x=1;x<2*N;x+=2)
				sum+=x;
			out.println(sum);
		}
		f.close();
	}
}
/*
Test data
5
11
16	
3
10
99

Test output
25
121
256
9
100
9801




*/