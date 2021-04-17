//Solution for Tri
import java.io.*;
import java.util.*;
import java.math.BigInteger;
import static java.lang.System.*;

public class Tri {
	public static void main (String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("tri.dat"));
		while(f.hasNext()){
				ArrayList<BigInteger> list = new ArrayList<BigInteger>(); 
				BigInteger a = new BigInteger(f.next());
				BigInteger b = new BigInteger(f.next());
				BigInteger c = new BigInteger(f.next());
				list.add(a);
				list.add(b);
				list.add(c);
				Collections.sort(list);
				for(BigInteger B:list)
					out.print(B+" ");
				if(a.add(b).compareTo(c)>0&&a.add(c).compareTo(b)>0&&c.add(b).compareTo(a)>0)
					out.println("YES");
				else
					out.println("NO");
		}
		f.close();
	}
}
/*
Judge's Input
1 2 3
2 2 3
3 3 6
3 7 3
3 2 2
14 12 17
8 8 5
10 7 2
87235612 83716253 2938475647
1234567890987654321 1234567890987654321 1234567890987654322
1000000000000000000000000 999999999999999999999999 999999999999999999999998
1000000000000000000000000 9999 999999999

Judge's Output
1 2 3 NO
2 2 3 YES
3 3 6 NO
3 3 7 NO
2 2 3 YES
12 14 17 YES
5 8 8 YES
2 7 10 NO
83716253 87235612 2938475647 NO
1234567890987654321 1234567890987654321 1234567890987654322 YES
999999999999999999999998 999999999999999999999999 1000000000000000000000000 YES
9999 999999999 1000000000000000000000000 NO
*/