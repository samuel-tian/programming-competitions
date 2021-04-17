import static java.lang.System.*;
import java.io.*;
import java.util.*;
import java.math.*;

public class Factorial
{
	public static void main(String[] args)throws IOException
	{
		Scanner sc = new Scanner(new File("factorial.dat"));
		int t = sc.nextInt(); 
		for(int x=0;x<t;x++)
		{
			int count=0;
			int num1 = sc.nextInt();
			BigInteger num = new BigInteger(Integer.toString(num1)); 
			BigInteger ans = new BigInteger("1");
			for(int y=1;y<=num1;y++)
			{
				ans=ans.multiply(new BigInteger(Integer.toString(y)));
			}
		
			BigInteger ten = new BigInteger("10");
			
			while((ans.remainder(ten)).equals(new BigInteger("0")))
			{
				count++;
				ans = ans.divide(ten); 
			}
			out.println(count);
			
		}
	}
}