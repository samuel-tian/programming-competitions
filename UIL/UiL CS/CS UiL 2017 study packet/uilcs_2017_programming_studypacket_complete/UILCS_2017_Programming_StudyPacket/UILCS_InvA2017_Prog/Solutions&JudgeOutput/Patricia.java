/*
UIL 2017 - Owen Solution
Invitational A
Patricia

Chance and probability have always interested Patricia, and she has been experimenting
with drawing red and green pebbles out of a sack, in different combinations. She has learned
the theory behind it all, and knows that the chances of drawing a single red pebble
out of a sack of both red and green marbles is simply a fraction with the numerator
being the number of red pebbles in the sack, and the bottom number being the total
number of red and green pebbles.  For example, if there are 8 red pebbles and 2 green pebbles
in the sack, the chances of removing a red pebble is 8 out of 10. The chances of
drawing a green pebble would be 2 out of 10.

She also knows that there are several combinations of two draws that can be
calculated. For example, if the same 8 red and 2 green marbles are in the bag,
the chance of drawing first a red, and then a green, depend on whether or not
you put back the first pebble.  If you do put it back, it the chances of this two
pebble combination would be the product of the two, which would be 8/10 times 2/10,
or 16/100.  However, if you did not replace the first pebble drawn, the chances of the
same combination increase to 16/90, the product of 8/10 and 2/9. She understands that
the number pebbles has reduced by 1, which is why the second fraction has the denominator of 9.

She needs your help in researching all possibilities, including drawing two of the same color,
with or without replacing the first pebble, and so on.


Input: An initial integer N, followed by N data sets.  
Each data set starts with the value P (1 or 2), indicating how many pebbles
are to be drawn out of the bag. Following that are two integers, indicating
how many red and green pebbles are in the bag. If 2 draws are to be made,
a letter Y or N indicates whether or not the first pebble will be put back in the
bag, followed by P instances of the letters 'R' or 'G', indicating the colors to be drawn. 

For example, the first data set below indicates
that one red pebble will be drawn from a bag containing 8 red and 2 green pebbles.

For the next data set, two pebbles (first a red, then a green) will be drawn from 
a bag initially containing 8 red and 2 green pebbles. The N indicates that the first
pebble will not be replaced.

Output: The non-reduced fraction representing the chances of drawing the pebble(s) indicated by the data set.

Sample input:
3
1 8 2 R
2 8 2 N R G
2 8 2 Y R G

Sample output:
8/10
16/90
16/100

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Patricia
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("patricia.dat"));
		int N = f.nextInt();
		while(N-->0){
				int picks = f.nextInt();
				int red = f.nextInt();
				int green = f.nextInt();
				boolean putBack = true;
				char pickOne=' ',pickTwo=' ';
				if(picks>1)
					putBack = f.next().charAt(0)=='Y';
				pickOne = f.next().charAt(0);
				if(picks>1)
					pickTwo = f.next().charAt(0);
				if(picks==1)
				{
					int nm = pickOne=='R'?red:green;
					Fraction f1 = new Fraction(nm,red+green);
					out.println(f1);
				}
				else
				{
					int num1 = pickOne=='R'?red:green;
					int num2 = pickTwo=='R'?red:green;
					Fraction f1 = new Fraction(num1,red+green);
					
					int put = putBack?0:1;
					Fraction f2 = new Fraction(num2,red+green-put);
					if(!putBack && pickOne==pickTwo)
						f2.num--;
					Fraction f3 = new Fraction(f1.num*f2.num,f1.den*f2.den); 
					out.println(f3);
			}
		}
		f.close();
	}
}
class Fraction{
	int num,den;
	Fraction(int n,int d){
		num=n;den=d;
	}
	public String toString(){
		return num+"/"+den;
	}
}
/*
Test data
11
1 8 2 R
2 8 2 N R G
2 8 2 Y R G
1 7 7 G
2 4 8 Y G R
2 5 11 Y R R
1 8 2 G
2 5 11 Y R G
2 6 8 N G R
2 10 8 N G G
2 10 8 N R R

Test output
8/10
16/90
16/100
7/14
32/144
25/256
2/10
55/256
48/182
56/306
90/306

*/