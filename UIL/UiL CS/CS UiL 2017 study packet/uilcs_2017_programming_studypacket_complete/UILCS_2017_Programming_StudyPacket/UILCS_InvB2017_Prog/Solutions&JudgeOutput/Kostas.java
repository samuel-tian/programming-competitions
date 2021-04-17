/*
UIL 2017 - Owen Solution
Invitational B
Kostas has just discovered the world of Leet Speak and found some references to it on the internet, including this one from www.urbandictionary.com:

Originating in the early 1980's, leet speak was first used by hackers as a way to prevent their websites/newsgroups from being found by simple keyword searches. Leet speak grew and became popular in online games such as Doom in the early 1990's as a way of suggesting that you were a hacker (h4x0r), and therefore to be feared. Leet, or 1337, is a short form of "elite," commonly used by video gamers to suggest that they are skilled. 
And this one from en.wikipedia.org:
Leet (or "1337"), also known as eleet or leetspeak, is an alternative alphabet for many languages that is used primarily on the Internet. It uses some characters to replace others in ways that play on the similarity of their glyphs via reflection or other resemblance. For example, leet spellings of the word leet include 1337 and l33t; eleet may be spelled 31337 or 3l33t. The term leet is derived from the word elite. The leet alphabet is a specialized form of symbolic writing. Leet may also be considered a substitution cipher, although many dialects or linguistic varieties exist in different online communities. The term leet is also used as an adjective to describe formidable prowess or accomplishment, especially in the fields of online gaming and in its original usage—computer hacking. ()
He decides to create one very similar using his own rules for the simple substitute cypher, based on the following table, including the digits 4, 8, 3, 6, and 1 for the letters A, B, E, G, and L, and the pipe symbol “|” included in in the substitutions for I, K, and P:

A	B	C	D	E	F	G	H	I	J	K	L	M	N	O	P	Q	R	S	T	U	V	W	X	Y	Z
4	8	[	)	3	|=	6	#	|	]	|<	1	^^	^	0	|o	9	2	5	7	(_)	\/	vv	><	/	%

He also decides on the following additional rules of priority, to give it a computer science flavor.
1.	Numbers and spaces are not replaced.
2.	Replace ER at the end of a word with XOR
3.	Replace OR at the end of a word with ZOR
4.	Replace AND, ANNED, and ANT at the end of a word with &
5.	Replace ED at the end of a word with *D
6.	Replace all remaining letters using the chart above.

Input: A list of words or phrases, each on one line.

Output: The “leet speak” version (“1337 5|o34|<”) of the word, according to the rules stipulated above.

Sample input:
UIL
R2D2
COMPUTER SCIENCE
STATE CHAMPION 2017

Sample output:
(_)|1
22)2
[0^^|o(_)7XOR 5[|3^[3
57473 [#4^^|o|0^ 2017

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Kostas
{
	public static void main(String [] args) throws IOException
	{
		String [] leet = {"4","8","[",")","3","|=","6","#","|","]","|<","1","^^","^","0","|o","9","2","5","7","(_)","\\/","vv","><","'/","%"};
		Scanner f = new Scanner(new File("kostas.dat"));
		while(f.hasNext())
		{
			args = f.nextLine().split(" ");
			String ans = "";
			for(String s:args)
			{
				String last = "";
				if(s.lastIndexOf("ER")==s.length()-2){
					s=s.substring(0, s.length()-2);
					last = "XOR";
				}
				else
					if(s.lastIndexOf("OR")>0 && s.lastIndexOf("OR")==s.length()-2){
						s=s.substring(0, s.length()-2);
						last = "ZOR";
					}
					else
						if(s.lastIndexOf("AND")>0 && s.lastIndexOf("AND")==s.length()-3){
							s=s.substring(0, s.length()-3);
							last = "&";
						}
						else
							if(s.lastIndexOf("ANNED")>0 && s.lastIndexOf("ANNED")==s.length()-5){
								s=s.substring(0, s.length()-5);
								last = "&";
							}
							else
								if(s.lastIndexOf("ANT")>0 && s.lastIndexOf("ANT")==s.length()-3){
									s=s.substring(0, s.length()-3);
									last = "&";
								}
								else
									if(s.lastIndexOf("ED")>0 && s.lastIndexOf("ED")==s.length()-2){
										s=s.substring(0, s.length()-2);
										last = "*D";
									}
				String ss = "";
				for(int x=0;x<s.length();x++)
					if(Character.isLetter(s.charAt(x)))
						ss+=leet[s.charAt(x)-65];
					else
						ss+=s.charAt(x);
					
				ans+=ss+last+" ";
			}
			out.println(ans.trim());
		}
	}
}
/*

Test data
UIL
R2D2
COMPUTER SCIENCE
STATE CHAMPION 2017
VICTORY KING AND QUEEN
C3PO
ERROR
ZOO
SWEEP
FANNED PLANT
AMPERSAND
BRANDED
JOROR
ELIXIR

Test output
(_)|1
22)2
[0^^|o(_)7XOR 5[|3^[3
57473 [#4^^|o|0^ 2017
\/|[702'/ |<|^6 4^) 9(_)33^
[3|o0
322ZOR
%00
5vv33|o
|=& |o1&
4^^|o325&
824^)*D
]02ZOR
31|><|2

*/