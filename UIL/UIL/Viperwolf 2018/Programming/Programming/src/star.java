import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class star {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner file = new Scanner(new File("star.dat"));
		int cases = file.nextInt();
		file.nextLine();
		while(cases-->0)
		{
			int st = file.nextInt();
			int max = -1;
			String name = "";
			
			while(st-->0)
			{
				String k = file.next();
				int n = file.nextInt();
				if(max<n)
				{
					max = n;
					name = k;
				}
				
			}
			System.out.println(name);
			
		}

	}
}
