/*
UIL 2017 - Lisa
Region

Lisa has decided to play around with her friends, well, with their names, anyway. She has just learned about how different letters of the alphabet have integer values that represent them. For example, the uppercase letter 'A' has a value of 65, and little 'a' has a value of 97. The values for 'B and 'b' are 66 and 98, and the rest of the alphabet follows in sequence.

She decides to calculate a "name weight" for each person, which consists of a complex formula. The formula takes three sums, averages those three sums, and then divides the average by the number of letters in each person's name.
The first sum is found by adding up the ASCII values for each person's name, just as it is, with the first letter in uppercase, and the rest in lower case. The second sum adds up all the ASCII values of the uppercased version of the name, and the third sum adds up the values for the lowercased version.

Using her own name as an example, the values for characters in the name "Lisa" are 76, 105, 115 and 97, which add up to 393. For the uppercased name, "LISA", the values are 76, 73, 83 and 65, for a total of 297. The lowercased name, "lisa", has ASCII values of 108, 105, 115 and 97, totaling 425. These three sums are added together... 393+297+425 ... to equal 1115, which is then divided by 3 to equal 371.66667, which is then divided by the length of her name, 4, to make 92.916667.

The output for each name is to include the original form of the name, the three sums in order – original, uppercased, lowercased – and the final “name weight” average, formatted to two decimal places.

Finally, all the names need to be output in descending order by the final "name weight" average, as shown below.

Input: Several names of friends, each on one line.

Output: All the names in descending order by "name weight" average, as described above and shown in the example below. The alignment must match EXACTLY as shown. It is guaranteed that the judge’s test data will have no names longer than those contained in this sample data.

Sample Input: 
Lisa
Alessandra
Brandon
Camilo
Denise

Sample Output:
Alessandra 1022  734 1054 93.67
Brandon     708  516  740 93.52
Lisa        393  297  425 92.92
Denise      600  440  632 92.89
Camilo      597  437  629 92.39
*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Lisa
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("lisa.dat"));
		ArrayList<Friend> list = new ArrayList();
		while(f.hasNext())
		{
			String name = f.next();
			list.add(new Friend(name));
		}
		Collections.sort(list);
		for(Friend ff:list)
			out.println(ff);
	}
}
class Friend implements Comparable<Friend>{
	String name;
	int sum,sumUpper,sumLower;
	double avg;
	Friend(String n)
	{
			name = n;
			sum = 0;
			sumUpper = 0;
			sumLower = 0;
			for(int x=0;x<n.length();x++)
				sum+=n.charAt(x);
			n = n.toUpperCase();
			for(int x=0;x<n.length();x++)
				sumUpper+=n.charAt(x);
			n = n.toLowerCase();
			for(int x=0;x<n.length();x++)
				sumLower+=n.charAt(x);
			avg = (sum+sumUpper+sumLower)/3.0/name.length();
	}
	public int compareTo(Friend f)
	{
		if(this.avg > f.avg)
			return -1;
		if(this.avg < f.avg)
			return 1;
		return 0;
	}
	public String toString()
	{
		return String.format("%-10s %4d %4d %4d %.2f",name,sum,sumUpper,sumLower,avg);
	}
}
/*
Test input:
Alessandra
Brandon
Camilo
Denise
Edward
Fabiana
Honza
Lisa
Manuela
Rishi
Suhani
Tanvi
David
Shyamal
John
Crystal
Kirby
Joel

Test Output:
Crystal     738  546  770 97.81
Tanvi       514  386  546 96.40
Kirby       513  385  545 96.20
Honza       512  384  544 96.00
Rishi       511  383  543 95.80
Suhani      616  456  648 95.56
Shyamal     719  527  751 95.10
John        399  303  431 94.42
Alessandra 1022  734 1054 93.67
Brandon     708  516  740 93.52
Manuela     707  515  739 93.38
Joel        394  298  426 93.17
Lisa        393  297  425 92.92
Denise      600  440  632 92.89
Edward      599  439  631 92.72
Camilo      597  437  629 92.39
David       488  360  520 91.20
Fabiana     674  482  706 88.67

*/