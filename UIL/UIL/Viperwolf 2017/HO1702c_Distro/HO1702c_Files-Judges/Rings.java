import java.util.Scanner;
import java.io.File;

public class Rings
{
	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(new File("rings.dat"));
		
		int n = fin.nextInt();
		fin.nextLine();
		
		char band = 'A';
		double prev = fin.nextDouble();
		double sum = prev;
		int count = 1;
		
		for (int i = 1; i < n; i++)
		{
			double next = fin.nextDouble();
			if (prev * 2 <= next || prev >= next * 2) {
				double avg = sum / count;
				if (avg < 10.0) { System.out.println("-------"); }
				else { System.out.printf("%c Ring: %.3f\n", band++, avg); }
				sum = 0;
				count = 0;
			}
			sum += next;
			count++;
			prev = next;			
		}
		double avg = sum / count;
		if (avg < 10.0) { System.out.println("-------"); }
		else { System.out.printf("%c Ring: %.3f\n", band++, avg); }
		
		fin.close();
	}
}