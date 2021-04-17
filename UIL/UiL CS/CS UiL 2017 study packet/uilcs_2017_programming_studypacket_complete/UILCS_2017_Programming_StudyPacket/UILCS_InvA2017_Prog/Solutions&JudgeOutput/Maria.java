/*
UIL 2017 - Owen Solution
Invitational A
Maria

Maria is writing a game program and needs your help displaying the different faces of a common six-sided die.

Write a program to input an integer in the range of 1-6 and output the corresponding 3X3 pattern that represents the value, with "*"s for the dots and "-"s for the spaces.

For example, if the input is 5, the output would be:
*-*
-*-
*-*

For the values 2 and 3, make the diagonal go from top left to bottom right.
The middle dot will only be used for odd dice values.

Input: Several integers, all on one line, separated by single spaces.

Output: The corresponding 3X3 pattern representing the die face for that value.
Follow each die face output with a blank line.

Sample input:
5 1 4

Sample output:
*-*
-*-
*-*

---
-*-
---

*-*
---
*-*

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Maria
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("maria.dat"));
		while(f.hasNext()){
			int N = f.nextInt();
			switch(N){
				case 1:one();break;
				case 2:two();break;
				case 3:three();break;
				case 4:four();break;
				case 5:five();break;
				case 6:six();
			}
		}
		f.close();
	}
	static void one()	{
		out.println("---");
		out.println("-*-");
		out.println("---");
		out.println();
	}
	static void two()	{
		out.println("*--");
		out.println("---");
		out.println("--*");
		out.println();
	}
	static void three()	{
		out.println("*--");
		out.println("-*-");
		out.println("--*");
		out.println();
	}
	static void four()	{
		out.println("*-*");
		out.println("---");
		out.println("*-*");
		out.println();
	}
	static void five()	{
		out.println("*-*");
		out.println("-*-");
		out.println("*-*");
		out.println();
	}
	static void six()	{
		out.println("*-*");
		out.println("*-*");
		out.println("*-*");
		out.println();
	}
}
/*
Test data
5 1 4 2 6 3
Test output
*-*
-*-
*-*

---
-*-
---

*-*
---
*-*

*--
---
--*

*-*
*-*
*-*

*--
-*-
--*

*/