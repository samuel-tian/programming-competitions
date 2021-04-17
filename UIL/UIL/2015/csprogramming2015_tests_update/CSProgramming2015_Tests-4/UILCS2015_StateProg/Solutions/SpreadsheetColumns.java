import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class SpreadsheetColumns
{
	public static int titleToNumber(String str)
	{
		int length = str.length() - 1;
		int i = 0;
		int result = 0;

		while (length >= 0)
		{
			result += (str.charAt(i++) - 'A' + 1) * (int)Math.pow(26, length);

			--length;
		}

		return result;
	}   


	public static void main(String[] args) throws FileNotFoundException
	{
		File file = new File ("spreadsheetcolumns.dat");
		Scanner sc = new Scanner(file);

		int num_tests = sc.nextInt();

		while (num_tests-- > 0)
		{
			int minutes = sc.nextInt();
			String rows = sc.next();
			String cols = sc.next();

			int realRows = 0;
			int realCols = 0;

			try
			{
				realRows = Integer.parseInt(rows);
			}
			catch (Exception e) {}
			
			try
			{
				realCols = Integer.parseInt(cols);
			}
			catch (Exception e) {}
			
			if (realRows == 0)
			{
				realRows = titleToNumber(rows);
			}
			
			if (realCols == 0)
			{
				realCols = titleToNumber(cols);
			}

			System.out.println(minutes * realRows * realCols);
		}

		sc.close();
	} 
}