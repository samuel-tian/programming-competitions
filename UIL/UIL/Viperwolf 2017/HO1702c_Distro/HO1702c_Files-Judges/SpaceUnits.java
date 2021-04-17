import java.util.Scanner;
import java.io.File;

public class SpaceUnits
{
	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(new File("spaceunits.dat"));
		
		int n = fin.nextInt();
		fin.nextLine();

		for (int i = 0; i < n; i++)
		{
			String line = fin.nextLine();
			int space = line.indexOf(" ");
			System.out.print(line.substring(0, space) + ".00 space-");
			
			String unit = line.substring(space + 1);
			if (unit.equals("m")) { System.out.println("meters"); }
			if (unit.equals("g")) { System.out.println("grams"); }
			if (unit.equals("s")) { System.out.println("seconds"); }
			if (unit.equals("N")) { System.out.println("newtons"); }
			if (unit.equals("Hz")) { System.out.println("hertz"); }
		}
		
		fin.close();
	}
}