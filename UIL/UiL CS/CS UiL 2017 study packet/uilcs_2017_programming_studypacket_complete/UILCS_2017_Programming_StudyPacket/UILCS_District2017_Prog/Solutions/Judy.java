/*
UIL 2017 - Owen Solution - Judy
District

Sample input:
MNA CJD JKL D-M
SAL ATR
HB- BA- ADE
Sample output:
14
1
3

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Judy
{
	static 
		Scanner k = new Scanner(in);
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("judy.dat"));
		Scanner k = new Scanner(in);
		while(f.hasNext())
		{
			String s = f.nextLine();
			args = s.trim().split(" ");
			Set<String> set = new HashSet<String>();
			//identify root triple
			for(String ss:args)
				set.add(ss);
			int root = 0;//assume first triple is the root
			for(int x=0;x<args.length;x++)
			{
				root = x;
				boolean flag = true;
				for(int y=0;y<args.length;y++)
					if(x!=y&&args[y].contains(args[x].substring(0,1)))
					{
							flag = false;
							break;
					}
				if(flag)
					break;
			}
			char[]list=new char[200];
			Arrays.fill(list,'-');
			int pos = 0;
			String triple = args[root];
			list[0]=triple.charAt(0);
			while(set.size()>0){
				//recursive method to process a single triple
				processTriple(list,triple,pos,set);
				int p=0;
				for(char c:list){
					if(c=='A')
						out.println(p);
					p++;
				}
			}
		}
		f.close();
	}
		static void processTriple(char[]list,String triple, int pos, Set<String> set)
		{
				if(triple.length()==0)
					return;
				list[pos*2+1]=triple.charAt(1);
				list[pos*2+2]=triple.charAt(2);
				set.remove(triple);
				
				//process left child triple, if any
				String left = "";
				if(set.size()>0&&triple.charAt(1)!='-')
					for(String t:set){
						if(t.substring(0,1).equals(triple.substring(1,2)))
						{
							left = t;
							break;
						}
					}
				if(left.length()>0)
				processTriple (list,left,pos*2+1,set);
				
				//process right child triple, if any
				String right = "";
				
				if(set.size()>0&&triple.charAt(2)!='-')
					for(String t:set){
						if(t.substring(0,1).equals(triple.substring(2,3)))
						{
							right = t;
							break;
						}
					}
				if(right.length()>0)
				processTriple (list,right,pos*2+2,set);
				
				}
}
/*
Test data
MNA CJD JKL D-M
SAL ATR
HB- BA- ADE
XW- WJB BCA
D-G G-H H-C C-A A-X X-Z
X-Z A-X C-A H-C G-H D-G
BCD DAE
BCD DEA
BCD DEF E-X FGH GA- CJK
E-X CJK FGH G-A BCD DEF
ABC

Test output
14
1
3
10
30
30
5
6
27
28
0

*/