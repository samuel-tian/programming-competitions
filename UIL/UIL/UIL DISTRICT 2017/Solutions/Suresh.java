/*
UIL 2017 - Owen Solution - Suresh
District

Sample input: (each paragraph will be all on one line in the data file)
To be or not to be, that's the question.
A wise man is not one who knows all the answers. But one who knows how to find the answers. A foolish man is one who knows neither.
Did he ever return? No, he never returned and his fate is still unknown. He may ride forever neath the streets of Boston, he's the man who never returned.
Oh, somewhere in this favored land the sun is shining bright, the band is playing somewhere, and somewhere hearts are light. And somewhere men are laughing, and little children shout; but there is no joy in Mudville. Mighty Casey has struck out.

Sample output:
1 9 question
3 11 answers 9 answers 8 neither
3 4 return 10 returned 15 returned
3 21 somewhere 16 somewhere 5 struck

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Suresh
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("suresh.dat"));
		Scanner k = new Scanner(in);
		while(f.hasNext())
		{
			String s = f.nextLine();
			args = s.split("[.?] ");
			String [][] words = new String [args.length][];
			for(int x=0;x<args.length;x++)
				words[x]=args[x].trim().split("[,:;. ]+");
			out.print(args.length+" ");
			for(int x=0;x<words.length;x++){
					out.print(words[x].length+" ");
					int longest=0;
					int i=0;
					for(int y=0;y<words[x].length;y++){
						if(words[x][y].length()>=longest){
							longest = words[x][y].length();
							i = y;
						}
					}
					out.print(words[x][i]+" ");
			}
			out.println();
		}
		f.close();
	}
}
/*
Test data
To be or not to be, that's the question.
A wise man is not one who knows all the answers. But one who knows how to find the answers. A foolish man is one who knows neither.
Did he ever return? No, he never returned and his fate is still unknown. He may ride forever neath the streets of Boston, he's the man who never returned.
Oh, somewhere in this favored land the sun is shining bright, the band is playing somewhere, and somewhere hearts are light. And somewhere men are laughing, and little children shout; but there is no joy in Mudville. Mighty Casey has struck out.
Whose woods these are? I think I know. His house in the village though. He will not see me stopping here, to watch his woods fill up with snow.
My little horse must think it queer, to stop without a farmhouse near. Between the woods and frozen lake: the darkest evening of the year. 
He gives his harness bells a shake, to ask if there is some mistake. The only other sound's the sweep of easy wind and downy flake.
These woods are lovely, dark, and deep; but I have promises to keep, and miles to before I sleep, and miles to before I sleep.

Test output
1 9 question
3 11 answers 9 answers 8 neither
3 4 return 10 returned 15 returned
3 21 somewhere 16 somewhere 5 struck
4 4 these 4 think 6 village 15 stopping
2 13 farmhouse 12 evening
2 14 mistake 12 sound's
1 25 promises

*/