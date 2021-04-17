/*
UIL 2017 - Owen Solution
Invitational B

Isidora has just learned about bit string flicking, specifically the left shift, right shift, left circle, and right circle operations.

She needs help writing a program that will correctly output the resulting binary string for
one of these four operations.

She wants to use RS for Right Shift, LS for Left Shift, RC for Right Circle, and LC for Left Circle as the first part of the command.
This will be followed by a dash "-", a value, then a space, and then the base ten integer value to be shifted or circulated.

For example, the command RS-4 45 will take the value 45, convert it to the binary string 101101, and then perform
a Right Shift 4, which means the rightmost 4 bits are eliminated, leaving 10 as the result.

The command LS-2 13 will convert the value 13 to its binary equivalent of 1101, and perform a 
Left Shift 2 operation, which essentially adds two zeroes to the back of the binary string,
resulting in 110100.

The circle commands result in a same size binary string as the original, with a Right Circle taking
the rightmost bits and circling them to the other side, and likewise for the Left Circle.

For example, the command RC-3 81 will take the binary value for 81, 1010001, take the three
right most digits, "001", and circulate them to the front of the string resulting in
0011010.

Input: Several commands as described above, each on one line. It is guaranteed that the command
will work within the length of the string, with all results greater than or equal to zero.

Output: The resulting bit string for the command.

Sample input:
RS-4 45
LS-2 13
RC-3 81

Sample output:
10
110100
0011010

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Isidora
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("isidora.dat"));
		while(f.hasNext())
		{
			String s = f.nextLine();
			args = s.split("[ -]");
			String op = args[0];
			int num1 = Integer.parseInt(args[1]);
			int num2 = Integer.parseInt(args[2]);
			String bits = Integer.toBinaryString(num2);
//			out.println(op + " " + num1 + " " + num2 + " "+bits);
			out.println(convert(op,num1,bits));
		}
		
	}
	static String convert(String o,int n,String b)
	{
		String zero = "0000000000000000000000000000000000000";
		String result = "";
		switch(o)
		{
			case "RS":result = b.substring(0,b.length()-n);break;
			case "LS":result = b+zero.substring(0,n);break;
			case "RC":result = b.substring(b.length()-n)+b.substring(0,n+1);break;
			case "LC":result = b.substring(n)+b.substring(0,n);break;
		}
		if(result.equals(""))
			result = "0";
		return result;
	}
}
/*
Test data
RS-4 45
LS-2 13
RC-3 81
LC-5 119
LS-5 513
RC-5 181
LC-8 999
RS-10 1200
RS-11 1200
RC-10 1200
LC-10 1200

Test output
10
110100
0011010
1111101
100000000100000
10101101101
1111111001
1
0
001011000010010110000
01001011000
*/