import java.util.Scanner;
import java.io.File;

public class Oracle
{
	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(new File("oracle.dat"));
		
		int n = fin.nextInt();
		fin.nextLine();
		
		int[] periods = new int[n];
		for (int i = 0; i < n; i++) { periods[i] = fin.nextInt(); }
		
		n = fin.nextInt();
		fin.nextLine();

		for (int i = 0; i < n; i++) {
			String[] planets = fin.nextLine().split("\\s");
			
			int lcm = periods[planets[0].charAt(0) - 'b'];
			for (int j = 1; j < planets.length; j++) {
				int b = periods[planets[j].charAt(0) - 'b'];
				
				lcm = lcm(lcm, b);
			}
			System.out.println(lcm);
		}
		
		fin.close();
	}
	
	private static int lcm(int a, int b) {
		return (a * b / gcd(a, b));
	}
	
	private static int gcd(int a, int b){
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}
}