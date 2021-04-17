/**
Heng just learned about CRC (cyclic redundancy check) in networking class and has looked up what Wikipedia says about it, which is:
"A cyclic redundancy check (CRC) is an error-detecting code commonly used in digital networks and storage devices to detect accidental changes to raw data. Blocks of data entering these systems get a short check value attached, based on the remainder of a polynomial division of their contents."

Essentially, when a message is sent, two other things are sent: a key, and a checksum.  The receiver performs an algorithm on the message using the key and determines if the remainder matches the checksum that is sent.

He decides to find a simple way of doing this, and discovered this simple algorithm.

First he starts with a binary string represented by the hex value 098, which represents some data, and decides on a key value of 5.
The equivalent binary strings for these two hex values are:
000010011000 and 0101

The process he discovers uses long division modulo 2 in binary, but instead of subtracting it uses the bitwise XOR process to reduce the message.

The process for the data example given would look like this:

000010010000 divided by 0101

000010011000
    101
    ___
      111
      101
      ___
       100
       101
       ___
         100
         101
         ___
          01
                  
He carefully notes that only the remainder after the XOR process is important, and that the final remainder
should be expressed using the number of significant digits of the key, minus 1.
In the example above, since the key, 0101, has three signficant digits (the leading zero does not count), the 
final remainder must be expressed in two SD, or 01.

Input - Several pairs of hex values, each pair on one line, separated by a single space. 

Output - For each pair of input values, calculate and output the final checksum as described and demonstrated above.

Sample data:
098 5
F 3
AC 5
71C A
8E6B 6

Sample Output:
01
0
11
000
01


 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import static java.lang.System.*;
public class Heng{
	public static void main(String [] args) throws FileNotFoundException {
		Scanner f = new Scanner(new File("heng.dat"));
		while(f.hasNext()) 
			{
			int m = Integer.parseInt(f.next(),16);
			String M = Integer.toBinaryString(m);
			int k = Integer.parseInt(f.next(),16);
			String K = Integer.toBinaryString(k);
			int mL=M.length();
			int kL = K.length();
			String KK = "";
			while(mL>=kL)
			{
				KK=(mL>kL)?(K+String.format("%0"+(mL-kL)+"d",0)):K;
				
				String s = "";
				for(int i=0;i<M.length();i++)
					s+=M.charAt(i)==KK.charAt(i)?"0":"1";
				int pos = s.indexOf("1");
				if(pos>=0)
					M=s.substring(pos);
					else
						M="0";
						
				mL=M.length();
			}
			int l = kL-1-M.length();
			out.println("00000".substring(0,l)+M);
		}
	}
}
/*
Test Data:
098 5
F 3
AC 5
71C A
8E6B 6
3A 2
F7 5
15C E
0F 3
2C 3
06D B
06D 0B
3FF 1B
332 2
01B5 7

Test Output:
01
0
11
000
01
0
10
010
0
1
100
100
0110
0
10

*/