/*
UIL 2017 - Owen Solution - Gan
District

Sample input:
2 5 3 12

Sample output:
--------------------------------------
 2     12.6     12.6     50.3     33.5
 5     31.4     78.5    314.2    523.6
 3     18.8     28.3    113.1    113.1
12     75.4    452.4   1809.6   7238.2
--------------------------------------
*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
import static java.lang.Math.*;
class Gan
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("gan.dat"));
		out.println("--------------------------------------");
		while(f.hasNext())
		{
			int rad = f.nextInt();
			double circum = 2*PI*rad;
			double area = pow(rad,2)*PI;
			double surfArea = 4*area;
			double vol = surfArea*rad/3;
			out.printf("%2d%9.1f%9.1f%9.1f%9.1f\n",rad,circum,area,surfArea,vol);
		}
		out.println("--------------------------------------");
	}
}
/*
Test data
2 5 3 12 25 20 33 39

Test output
--------------------------------------
 2     12.6     12.6     50.3     33.5
 5     31.4     78.5    314.2    523.6
 3     18.8     28.3    113.1    113.1
12     75.4    452.4   1809.6   7238.2
25    157.1   1963.5   7854.0  65449.8
20    125.7   1256.6   5026.5  33510.3
33    207.3   3421.2  13684.8 150532.6
39    245.0   4778.4  19113.4 248474.8
--------------------------------------

*/