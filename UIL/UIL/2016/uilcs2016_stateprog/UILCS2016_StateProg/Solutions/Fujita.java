/**
Fujita is fascinated with number bases, specifically with the log values of different numbers in 
different bases.

He decides to experiment by writing a program that will output bar graphs using this idea, but 
needs your help.  He wants the program to produce a horizontal bar graph whose length represents 
the log of a value given a certain base.  For example, for the value 1000 in base 2, the bar 
produced will have ten "*"s, since the log, base 2, of 1000 is approximately 10.  

For another value, 3671, and a base of 4, the bar graph produced contains six stars, indicating 
the approximate log value of 6, base 4, of the value 3671. He understands that this also is an 
approximation, since 4 to the power of 6 is actually 4096, but it is the closest log value that 
just exceeds 3671.

Input - Several pairs of positive integer values N and B, with N having up to 20 significant digits, 
and B having a value no greater than 10.

Output - For each pair of values, output the number of stars ("*") in a horizontal bar graph that represents the log value of N, base B, as described and demonstrated above.

Sample data:
1000 2
3671 4
9182736453 5

Sample Output:
**********
******
***************

 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import static java.lang.System.*;
public class Fujita{
	public static void main(String [] args) throws FileNotFoundException {
		Scanner f = new Scanner(new File("fujita.dat"));
		while(f.hasNext()) {
			long num=f.nextLong();
			int base=f.nextInt();
			while(num>0)
			{
				out.print("*");
				num/=base;
			}
			out.println();
		}
	}
}
/*
Test Data:
1000 2
3671 4
9182736453 5
98765 10
72615 3
2635481 9
9182736453 5
9223372036854775807 6

Test Output:
**********
******
***************
*****
***********
*******
***************
*************************

*/