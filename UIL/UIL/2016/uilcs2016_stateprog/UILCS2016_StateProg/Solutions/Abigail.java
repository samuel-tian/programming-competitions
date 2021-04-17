/**
Abigail has just learned to simplify radicals and needs you to write a program for her so she can check her work.

The rules she learned in the lesson were simple:

1. A radicand may not contain a perfect root factor
2. A radicand may not be negative

Her current homework has several expressions in the form A + B * sqr(C), where A, B, and C can be any integers, positive or negative, but only A might be zero.
The assignment is to simplify the radical in the same form.
The program is to input the initial values of A, B, and C, and then output the simplified values of A, B, and C, any of which could be zero.

Her teacher has guaranteed that all answers have possible values of A, B, and C, and that when B or C are equal to zero, it means there is no radical in the final solution.

For example, the data set 5 2 20 represents 5 + 2 * sqr(20), which can be simplified as such:
5 + 2 * sqr(4 * 5) = 5 + 2 * 2 * sqr(5) = 5 + 4 * sqr(5), resulting in the output values 5, 4 and 5.

For the data set 5 2 -20, the final output is 5 4i 5, with i representing the square root of -1.

Input - Several sets of three integer values, each set on one line. All three integers will be in the range -100...100, but only A might be zero.
Each set of three integers A, B, and C represents the radical expression A + B * sqr(C). 

Output - Simplify each expression according to the rules listed above, and output the final values of A, B, and C.  It is possible for any of the final three values to be zero.

Sample data:
5 2 20
5 2 -20
0 3 9
3 4 -25
0 9 3

Sample Output:
5 4 5
5 4i 5
9 0 0
3 20i 0
0 9 3

 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import static java.lang.System.*;
public class Abigail{
	static int[]primes={23,19,17,13,11,7,5,3,2};
	static boolean flag = false;//flag to show debugging output statements
	public static void main(String [] args) throws FileNotFoundException {
		Scanner f = new Scanner(new File("abigail.dat"));
		while(f.hasNext()) {
			int a = f.nextInt();
			int b = f.nextInt();
			int c = f.nextInt();
			if(flag)
			out.println(a + " " +b+" "+c);
			String s = factor(c);
			c=1;
			if(flag)out.println(s);
			String B = "";
			//parse out i, if any
			if(s.length()>0&&s.charAt(0)=='i'){
				B+="i";
				s=s.substring(2);
			}
			if(flag)out.println("B = "+B+":"+s);
			args=s.split(" ");
			int[]list=new int[args.length];
			for(int i=0;i<list.length;i++)
				list[i]=Integer.parseInt(args[i]);
			for(int i=0;i<list.length;i++)
				if(i<list.length-1&&list[i]==list[i+1])
				{
					b*=list[i];
					i++;
				}
				else
					c*=list[i];
			if(c==1)
				c=0;
			if(c==0&&B.indexOf("i")==-1){
				a+=b;
				b=0;
			}
			String A = ""+a;
			B = b+B;
			String C = ""+c;
			out.println(A + " " +B+" "+C);
			if(flag)out.println();
		}
	}
	static String factor(int c)
	{
		String list = "";
		int i = 0;
		if(c<0){
			list+="i ";
			c=-c;
		}
		while(c>1&&i<primes.length){
			if(c>=primes[i]&&c%primes[i]==0)
			{
				list+=primes[i]+" ";
				c/=primes[i];
			}
			else
				i++;
		}
		return list;
	}
}
/*
Test Data:
5 2 20
5 2 -20
0 3 9
3 4 -25
0 9 3
3 4 25
0 9 15
0 9 -15
0 1 15
0 1 25
0 1 18
0 1 40
0 3 -16
2 3 64

Test Output:
5 4 5
5 4i 5
9 0 0
3 20i 0
0 9 3
23 0 0
0 9 15
0 9i 15
0 1 15
5 0 0
0 3 2
0 2 10
0 12i 0
26 0 0

*/