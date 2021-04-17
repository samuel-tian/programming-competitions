/**
Dara has just learned about derivatives, is very confused, and needs your help with her homework, which for now only works on simple powers (no negative or fractional exponents).

She barely understands the rules of finding a derivative, which are:

1.	If the expression is a constant value, the derivative is zero.
2.	If the expression is any power in the form AX^N, where is A is a positive or negative integer, and N is any positive integer, the derivative is equal to A times N, times X raised to the power of N-1, or ANX^N-1.
3.	The derivative of a sum is the sum of the derivatives.

For example, the derivative of 8 is just 0, since 8 is a constant value. The derivative of X is 1, since A is implied to be 1, and the power of X is implied to be 1. N-1 is zero, and so X^0 is 1, therefore 1(A) times 1(N) times 1(X^0) is equal to 1.

The derivative of X^5 is 5 times 1 times X^4), or 5X^4.

The second derivative is simply the derivative of the first derivative, therefore the second derivative of X^5 is 20X^3, which is the first derivative of 5X^4, which was the first derivative of X^5.

Input - Several expressions of one or more terms separated by “ + “ or “ – “, in descending order of degree, with X as the only variable. All numeric values (coefficients or constants) will be positive integers. There will be no input fractional values.

Output - The first and second derivative of each expression, with " : " separating the two derivative expressions. Coefficient values of 1 or -1 are not allowed, and only one sign is allowed between terms. For example, 2X + -6 is not correct and should be expressed as 2X - 6. There will be no fractional output values.

Sample data:
8
X
X^5
5X^4
3X^3 - 5X + 8

Sample Output:
0 : 0
1 : 0
5X^4 : 20X^3
20X^3 : 60X^2
9X^2 - 5 : 18X 

 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import static java.lang.System.*;
public class Dara{
	public static void main(String [] args) throws FileNotFoundException {
		Scanner f = new Scanner(new File("dara.dat"));
		while(f.hasNext()) {
			String s = f.nextLine();
			String s2 = process(s);
			out.print(s2+" : ");
			out.println(process(s2));
		}
	}
	static String process(String s)
	{
			String [] args=s.split(" ");
			String der="";
			for(int x=0;x<args.length;x++)
				if(args[x].equals("-")||args[x].equals("+"))
					der+=(" "+args[x]+" ");
				else
					der+=d(args[x]);
					
			if(der.indexOf("+ 0")>-1||der.indexOf("- 0")>-1)
				return(der.substring(0,der.length()-4));
			else
				return(der);
	}
	static String d(String s)
	{
		if(s.equals("X"))
			return "1";
		if(s.indexOf("X")==-1)
			return "0";
		if(s.indexOf("^")==-1)			
			return s.substring(0,s.length()-1);
		String [] args = s.split("[X^]+");
		int[]nums=new int[2];
		if(args[0].equals(""))
			nums[0]=1;
		else
			nums[0]=Integer.parseInt(args[0]);
		nums[1]=Integer.parseInt(args[1]);
		
		
		nums[0]*=nums[1];
		nums[1]--;
		if(nums[1]>1)
			return nums[0]+"X^"+nums[1];
		else
		if(nums[1]==1)
			return nums[0]+"X";
		else
			return ""+nums[0];
	}
}
/*
Test Data:
8
X
X^5
5X^4
3X^3 - 5X + 8
X^2 + 13
X^2 - 6X + 10
-3X^4 + 5X^2
X^4 + X^3 + X^2 + X
10X^5 + 9X^4 + 8X^3 - 7X^2 - 6X + 10

Test Output:
0 : 0
1 : 0
5X^4 : 20X^3
20X^3 : 60X^2
9X^2 - 5 : 18X
2X : 2
2X - 6 : 2
-12X^3 + 10X : -36X^2 + 10
4X^3 + 3X^2 + 2X + 1 : 12X^2 + 6X + 2
50X^4 + 36X^3 + 24X^2 - 14X - 6 : 200X^3 + 108X^2 + 48X - 14
*/