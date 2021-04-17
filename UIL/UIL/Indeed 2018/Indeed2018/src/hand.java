import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class hand 
{

	public static void main(String[] args) throws FileNotFoundException 
	{
		Scanner file = new Scanner(new File("hand.dat"));
		
		long cases = file.nextLong();
		while(cases-->0)
		{
			long number_Of_knights = file.nextLong();
			long a = 1;
			long b = 1;
			
			long cnt =0;
			
			while(true)
			{
				long c = a+b;
				
				if(c>number_Of_knights)
				{
					break;
				}
				cnt++;
				a=b;
				b=c;
			}
			
			System.out.println(cnt);
		}

	}

}
