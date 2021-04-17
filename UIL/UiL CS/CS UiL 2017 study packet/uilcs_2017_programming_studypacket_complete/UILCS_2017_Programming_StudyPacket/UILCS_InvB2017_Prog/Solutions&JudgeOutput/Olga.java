/*
UIL 2017 - Owen Solution
Invitational B

To make output practice a bit more interesting, Olga has decided to read in the names of her friends
and output them with special characters around each name, depending on the characteristics of the name.

For any name that has an odd number of characters, she will but the name in single quotes, putting even
number length names in double quotes.  

In addition to that she will put single slashes outside of
names that begin with letters in the first half of the alphabet, 
and double slashes outside of names that start with letters in the last half of the alphabet. 

Finally, she will put single dashes around names with less than 6 characters, 
and the equals sign around longer names.

For example, her name will appear in the output as -\\"Olga"//-, double quotes for an even number of characters,
double slashes since her name starts with 'O', which is in the last half of the alphabet, and single dashes
since her name is less than 6 characters long.
  
The name of her friend Isidora will appear as: =\'Isidora'/=, single quotes for odd length, double slashes for last half of the alphabet,
and equals sign for a long name.


Input:
A list of names, each on one line. There will be no special characters inside of any name. 

Output: 
Each name surrounded by special characters, as described above.

Sample input:
Olga
Isidora
Fengge

Sample output:
-\\"Olga"//-
=\'Isidora'/=
=\"Fengge"/=

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Olga
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("olga.dat"));
		while(f.hasNext())
		{
			String s = f.next();
			String ss = s;
			if(ss.length()%2==1)
				s = "'"+s+"'";
			else
				s = "\""+s+"\"";

			if(ss.charAt(0)<='L')
				s = "\\"+s+"/";
			else
				s = "\\\\"+s+"/"+"/";
			
			if(ss.length()<6)
				s = "-"+s+"-";
			else
				s = "="+s+"=";
			
			out.println(s);
		}
		
	}
}
/*

Test data
Olga
Isidora
Fengge
Samantha
Akio
Danna
Evelyn
Juan
Kostas
Nastya
Pedro
Roy
Abcedfghijklmnop
Zyxwv

Test output
-\\"Olga"//-
=\'Isidora'/=
=\"Fengge"/=
=\\"Samantha"//=
-\"Akio"/-
-\'Danna'/-
=\"Evelyn"/=
-\"Juan"/-
=\"Kostas"/=
=\\"Nastya"//=
-\\'Pedro'//-
-\\'Roy'//-
=\"Abcedfghijklmnop"/=
-\\'Zyxwv'//-

*/