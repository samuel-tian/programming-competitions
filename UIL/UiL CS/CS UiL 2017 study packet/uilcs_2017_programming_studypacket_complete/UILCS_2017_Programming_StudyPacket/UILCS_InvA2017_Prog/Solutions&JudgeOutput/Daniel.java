/*
UIL 2017 - Owen Solution
Invitational A
Daniel - String Processing

Daniel considers himself a word smith of sorts, and loves pattern poetry, 
like haikus, cinquain poems, limericks, and such. 
He also makes it a hobby to find really cool quotes.  
One day he decided to form word triangles out of the quotes he found, 
and since he knew of no one else who had ever done that, 
decided to call them Daniel Triangles.

A Daniel Triangle starts with the first word of the quote on the first line, 
the next two words on the next line, then the next three on the third line, 
and so on. If however, the next line exceeds 30 characters, he starts another 
triangle in the same fashion, doing this over and over until the quote has ended.

In the first example below, a fairly short quote by Steve Martin, 
he puts the first word "Be" on the top line of the triangle, followed by
"so good" on the next line, then "they can't ignore" on the third, followed 
by the last word, the dash (he counts the dash as a word), and the author's name.

To separate each quote, and to make sure it does not exceed his self-imposed 
30-character limit, he puts a metric line of 30 characters, three sets of 
nine dashes, each set ending with an asterisk.

Input: Several quotes, each on one line. Each quote ends with a dash, followed by 
the author's name. All parts of the quote, including the dash and author's name, 
are separated by single spaces. Any punctuation marks are considered part of the 
word they follow or that contains them.

Output: A Daniel Triangle for each quote, as described above, followed by the 
30-character metric line as shown.

Sample input:
Be so good they can't ignore you. - Steve Martin
Ever tried? Ever failed? No matter. Try again. Fail again. Fail better. - Samuel Beckett
Impossible is just a big word thrown around by small men who find it easier to live in the world they've been given than to explore the power they have to change it. Impossible is not a fact. It's an opinion. Impossible is not a declaration. It's a dare. Impossible is potential. Impossible is temporary. Impossible is nothing. - Muhammed Ali

Sample output:
Be
so good
they can't ignore
you. - Steve Martin
---------*---------*---------*
Ever
tried? Ever
failed? No matter.
Try again. Fail again.
Fail better. - Samuel Beckett
---------*---------*---------*
Impossible
is just
a big word
thrown around by small
men who find it easier
to live in the world they've
been given than to explore the
power
they have
to change it.
Impossible is not a
fact. It's an opinion.
Impossible
is not
a declaration. It's
a dare. Impossible is
potential. Impossible is
temporary.
Impossible is
nothing. - Muhammed
Ali
---------*---------*---------*

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Daniel
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("daniel.dat"));
		while(f.hasNext()){
			args = f.nextLine().split(" ");
		int x = 0;
		String q = "";
		for(int r=0;r<10;r++)
		{
			for(int c=0;c<=r;c++)
			{
				if(x<args.length)
					if(q.length()+args[x].length()<=30)
						q+=args[x++]+" ";
					else
						r=-1;
			}
			out.println(q);
			q="";
			if(x>=args.length)break;
		}
		out.println("---------*---------*---------*");
		
		}
	f.close();
	}
}
/*
Test data
Be so good they can't ignore you. - Steve Martin
Ever tried? Ever failed? No matter. Try again. Fail again. Fail better. - Samuel Beckett
Impossible is just a big word thrown around by small men who find it easier to live in the world they've been given than to explore the power they have to change it. Impossible is not a fact. It's an opinion. Impossible is not a declaration. It's a dare. Impossible is potential. Impossible is temporary. Impossible is nothing. - Muhammed Ali
At the end of the day, let there be no excuses, no explanations, no regrets. - Steve Maraboli
Every life form seems to strive to its maximum except human beings. How tall will a tree grow? As tall as it possibly can. Human beings, on the other hand, have been given the dignity of choice. You can choose to be all or you can choose to be less. Why not stretch up to the full measure of the challenge and see what all you can do? - Jim Rohn

Test output
Be
so good
they can't ignore
you. - Steve Martin
---------*---------*---------*
Ever
tried? Ever
failed? No matter.
Try again. Fail again.
Fail better. - Samuel Beckett
---------*---------*---------*
Impossible
is just
a big word
thrown around by small
men who find it easier
to live in the world they've
been given than to explore the
power
they have
to change it.
Impossible is not a
fact. It's an opinion.
Impossible
is not
a declaration. It's
a dare. Impossible is
potential. Impossible is
temporary.
Impossible is
nothing. - Muhammed
Ali
---------*---------*---------*
At
the end
of the day,
let there be no
excuses, no explanations, no
regrets.
- Steve
Maraboli
---------*---------*---------*
Every
life form
seems to strive
to its maximum except
human beings. How tall will
a tree grow? As tall as
it possibly can. Human beings,
on
the other
hand, have been
given the dignity of
choice. You can choose to
be all or you can choose
to be less. Why not stretch up
to the full measure of the
challenge
and see
what all you
can do? - Jim
Rohn
---------*---------*---------*
I
AM THAT
I AM -
GOD
---------*---------*---------*
*/