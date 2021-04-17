/*
UIL 2017 - Owen Solution
District

Alexey’s cousin Isidora recently shared with her a new concept she had learned in CS class called bit string flicking, which included operations like left shift, right shift, left circle, and right circle operations. Alexey was fascinated with this new idea and decided to do some further research on it, and discovered other operations that were used with bit string manipulation, like NOT, AND, OR, and XOR, which she knew worked with logic operations, but now she discovered could also work with binary strings.

She continued using Isidora’s notation of using RS for Right Shift, LS for Left Shift, RC for Right Circle, and LC for Left Circle as the first part of the command structure, with a slight adaption of using a single space instead a dash, a value, another single space, and then the base ten integer value to be shifted or circulated. She added N for Not, A for AND, O for OR, and X for XOR, each preceding the operands, with single space separation. 

As she had learned from Isidora, the shift command RS 4 45 will take the value 45, convert it to the binary string 101101, and then perform a Right Shift 4, which means the rightmost 4 bits are eliminated, leaving 10 in binary as the result, which is equivalent to the base ten value 2. The command LS 2 13 converts the value 13 to its binary equivalent of 1101, and performs a Left Shift 2 operation, which essentially appends two zeroes to the back of the binary string, resulting in 110100, or 52 base ten.

The circle commands result in a same size binary string as the original, with a Right Circle taking the rightmost bits and circling them to the other side, and likewise for the Left Circle, taking the leftmost digits and circling them to the other side. For example, the command RC 3 81 will take the binary value for 81, or 1010001 in binary, take the three right most digits, 001, and circle them to the front of the string resulting in 0011010, which is 26 in decimal.

The four new commands would work like this. 
•	N 23 would take the binary equivalent for 23, which is 10111, and “flip” all of the bits, resulting in 01000, or just 1000, which is equivalent to the decimal integer value 8. 
•	The prefix style expression A 23 14 would perform the bitwise AND operation on the two values 23 and 14, which in binary would be 10111 AND 1110, resulting in 00110, or 6. 
•	The expression O 23 14 is equivalent to 10111 OR 1110, which results in 11111, or 31. 
•	The expression X 23 14 is equivalent to 10111 XOR 1110, which has a result of 11001, or 25 in base ten.

Input: Several commands as described above, each on one line. It is guaranteed that the command will work within the length of the string, with all results greater than or equal to zero.

Output: The resulting base ten value for the command.

Sample input:
RS 4 45
LS 2 13
RC 3 81
N 23
A 23 14
O 23 14
X 23 14
Sample output:
2
52
26
8
6
31
25

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Alexey
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("alexey.dat"));
		while(f.hasNext())
		{
			String s = f.nextLine();
			args = s.split(" ");
			out.println(convert(args));
		}
	}
	static int convert(String [] args)
	{
			if(args[0].matches("[RL]."))
			{
				String op = args[0];
				int num1 = Integer.parseInt(args[1]);
				int num2 = args.length==3?Integer.parseInt(args[2]):0;
				String bits = Integer.toBinaryString(num2);
				return Integer.parseInt(convert(op,num1,bits),2);
			}
			else if(args[0].contains("N"))
				return convert (args[1]);
			return convert(args[0],args[1],args[2]);
	}
	
	static int convert(String val)//NOT
	{
		String s = "";
		String bits = Integer.toBinaryString(Integer.parseInt(val));
		for(int x = 0;x<bits.length();x++)
			s+=bits.charAt(x)=='0'?'1':'0';
		return Integer.parseInt(s,2);
	}
	static int convert(String op, String val1, String val2)//AND, OR, XOR
	{
		int num1 = Integer.parseInt(val1);
		int num2 = Integer.parseInt(val2);
		switch(op)
		{
			case "A":return num1&num2;
			case "O":return num1|num2;
			case "X":return num1^num2;
		}
		return 0;
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
RS 4 45
LS 2 13
RC 3 81
N 23
A 23 14
O 23 14
X 23 14
LC 5 119
O 99 100
LS 5 513
X 255 390
RC 5 181
LC 8 999
N 256
RS 10 1200
RS 11 1200
A 632 15
RC 10 1200
LC 10 1200

Test output
2
52
26
8
6
31
25
125
103
16416
377
1389
1017
255
1
0
8
361648
600
*/