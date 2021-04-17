import java.util.Scanner;
import java.io.File;

public class Fuel
{
	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(new File("fuel.dat"));
		
		int n = fin.nextInt();
		fin.nextLine();
		
		double G = 6.67e-11;										// Nm^2/kg^2
		double isp = 340;											// s
		double altitude = 200 * 1000;								// km * 1000 = m
		double mShip = 1;											// kg (independent)
		
		for (int i = 0; i < n; i++)
		{
			double M = fin.nextDouble();							// kg
			double r = fin.nextDouble() * 1000;						// km * 1000 = m
			double g = fin.nextDouble();							// m/s^2
			
			double vOrbit = Math.sqrt(G * M / (r + altitude));		// m/s
			double vExhaust = isp * g;								// m/s
			double wetToDry = Math.pow(Math.E, (vOrbit / vExhaust));
			System.out.printf("%.2f:1\n", wetToDry);
		}
		
		fin.close();
	}
}