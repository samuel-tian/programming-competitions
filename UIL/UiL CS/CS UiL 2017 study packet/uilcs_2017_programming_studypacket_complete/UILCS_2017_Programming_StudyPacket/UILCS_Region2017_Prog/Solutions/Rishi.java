/*
UIL 2017 - Rishi
Region

Data compression is new to Rishi in his computer study, and he is fascinated with it.  He has been experimenting with different methods and needs your help with a process called run-length encoding, which simply counts sequences of like data and creates a shorter string in a coded fashion.
For example, the string in the first sample data item below has several instances of repeated letters, which can be encoded into a shorter string by counting the number of instances of the letter and listing that letter once, preceded by the number of occurrences of that letter.
As you can see, the letter 'A' occurs 4 times at the start, which results in the coded string "4A". 
That is followed by 4 Bs, 2 As, 6 Cs, and 7 Ds, resulting in the encoded string shown.

Decompressing such a string is a simple task as well. Simply work through the encoded string and expand it, as shown in the second example.
The first number/letter pair is 12X, which means "XXXXXXXXXXXX", followed by "YYYY" and "ZZZZZZZZZZZZ".

Input: A string to be compressed, or a compressed string to be decompressed. The string to be compressed will contain only uppercase letters, and the encoded string will contain a series of number/letter pairs.

Output: The resulting decompressed, or compressed, string from the given input.

Sample Input: 
AAAABBBBAACCCCCCDDDDDDD
12X4Y12Z
RSRSRSRRRRRRRRSSSSSSSSSSSSSST
6W3B9W4B3W

Sample Output:
4A4B2A6C7D
XXXXXXXXXXXXYYYYZZZZZZZZZZZZ
1R1S1R1S1R1S8R14S1T
WWWWWWBBBWWWWWWWWWBBBBWWW
*/

import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Rishi
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("rishi.dat"));
		while(f.hasNext())
		{
			String s = f.next();
			if("123456789".contains(s.substring(0,1)))
			//decompress
			{
				String dc = "";
				while(s.length()>0)
				{
					int x = 0;
					String num = "";
					while("123456789".contains(s.substring(x,x+1)))
					{
						num+=s.substring(x,x+1);
						x++;
					}
					char a = s.charAt(x);
					s=s.substring(x+1);
					x = Integer.parseInt(num);
					for(int y=0;y<x;y++)
						dc+=""+a;
				}
				out.println(dc);
			}
			else
			//compress
			{
				String dc = "";
				int num = 1;
				for(int x=0;x<s.length()-1;x++)
				{
					char a = s.charAt(x);
					if(a==s.charAt(x+1))
						num++;
					else{
						dc+=""+num+a;
						num=1;
					}
				}
				dc+=""+num+s.charAt(s.length()-1);
				out.println(dc);
			}			
			
		}
	}
}

/*
Test input:
AAAABBBBAACCCCCCDDDDDDD
12X4Y12Z
RSRSRSRRRRRRRRSSSSSSSSSSSSSST
6W3B9W4B3W
AAAAAABBBB
AABBCCDDDDA
7C5D3C
1A1B1C4D6C
AAAAEAAAAAEEAAAAAAE

Test Output:
4A4B2A6C7D
XXXXXXXXXXXXYYYYZZZZZZZZZZZZ
1R1S1R1S1R1S8R14S1T
WWWWWWBBBWWWWWWWWWBBBBWWW
6A4B
2A2B2C4D1A
CCCCCCCDDDDDCCC
ABCDDDDCCCCCC
4A1E5A2E6A1E

*/