import java.util.Scanner;
import java.io.File;

public class Sexagesimal
{
	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(new File("sexagesimal.dat"));
		
		int n = fin.nextInt();
		fin.nextLine();

		for (int i = 0; i < n; i++) {
			fin.next();												//	"RA"
			double ra = toDecimal(fin.next().trim()) * 15;
			fin.next();												//	" | "
			fin.next(); 											//	"Dec"
			double dec = toDecimal(fin.next().trim());
			System.out.printf("RA %.3f | Dec %+.3f\n", ra, dec);
		}
		
		fin.close();
	}
	
	private static double toDecimal(String hexagesimal) {
		int sign = (hexagesimal.charAt(0) == '-') ? -1 : 1;
		String[] hhmmss = hexagesimal.trim().split(":");
		int hh = Integer.parseInt(hhmmss[0]);
		int mm = Integer.parseInt(hhmmss[1]);
		int ss = Integer.parseInt(hhmmss[2]);
		return sign * (Math.abs(hh) + (mm / 60.0) + (ss / 3600.0));
	}
}