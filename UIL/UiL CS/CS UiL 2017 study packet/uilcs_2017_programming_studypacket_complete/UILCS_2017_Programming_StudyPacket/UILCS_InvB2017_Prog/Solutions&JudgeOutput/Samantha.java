/*
UIL 2017 - Owen Solution - Samantha

Invitational B

Samantha's boss has given her a bunch of data to process, but she is not clear on what it represents, nor is she told. 
However, the criteria for processing the data is given with some formulas and expected outputs, so she happily starts
to code the solution.

The format of each data set is a series of integers, each on one line. The first integer is an index
value X to be used in a formula, followed by an integer N, followed by N more integers representing 
the data, sometimes in ascending order, but not always.  

The three requested outputs are:
	A mean of the list of values
	The median value of the list
	A value (whose meaning is unclear) based on a complex formula
All three values are to be output as truncated integers.

The formula she is to use for calculating the third output is based on three variables and a few constants. 
The three variables are:
 - The index value X at the front of each data set.
 - The sum of all values below the mean, called the low sum, or LS, for short.
 - The sum of all values equal to or above the mean, called the high sum, or HS, for short.

The formula is: (.06 + X * .07) * LS) +( 4 * X * .0789 * HS)
 
Input: Several integer values, all on one line with single space separation, including X and N followed by N values.  

Output: Three integer values as described above.

Sample input:
4 5 10 75 1000 25000 75000
5 6 200 300 1000 50000 200000 750000
7 7 1 5 10 400000 500000 750000 1000000

Sample output:
20217 1000 126608
166916 25500 1520214
378573 400000 5854388

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Samantha
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("samantha.dat"));
		while(f.hasNext())
		{
		int X = f.nextInt();
		
		int n = f.nextInt();
		int N = n;
		ArrayList<Integer> list = new ArrayList();
		int sum = 0;
		while(n-->0){
			int b = f.nextInt();

			list.add(b);
			sum+=b;
		}

		Collections.sort(list);
		int mean = (int)(sum*1.0/N);
		out.print(mean+" ");
		int med = 0;
		if(N%2==0)
			med = (list.get(N/2)+list.get(N/2-1))/2;
		else
			med = list.get(N/2);
		out.print(med+" ");
		
		int LS = 0;
		int HS = 0;
		for(int a:list)
			if(a<mean)
				LS+=a;
			else
				HS+=a;
		int offer = (int)(((.06+X*.07)*LS)+(4*X*.0789*HS));
		out.println(offer);
		}
	}
}
/*
Test data
4 5 10 75 1000 25000 75000
5 6 200 300 1000 50000 200000 750000
7 7 1 5 10 400000 500000 750000 1000000
6 3 1000 10000 100000
5 5 5000 100 75 50 5
4 6 5000 400000 25000 200000 50000 100000
2 8 100000 5000 200000 1000 750000 750 1000000 50
6 5 100 1 500 500000 750000

Test output
20217 1000 126608
166916 25500 1520214
378573 400000 5854388
37000 10000 194640
1046 75 7984
130000 75000 818640
257100 52500 1165960
250120 500 2367288

*/