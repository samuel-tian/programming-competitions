import java.util.Scanner;
import java.io.File;

public class DryRun
{
	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(new File("dryrun.dat"));
		
		int n = fin.nextInt();
		fin.nextLine();

		for (int i = 0; i < n; i++)
		{
			System.out.println("I like " + fin.nextLine() + ".");
		}
		
		fin.close();
	}
}