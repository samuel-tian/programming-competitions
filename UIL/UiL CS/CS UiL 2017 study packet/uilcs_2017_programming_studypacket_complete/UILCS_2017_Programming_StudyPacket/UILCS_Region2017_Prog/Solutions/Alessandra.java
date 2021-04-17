/*
UIL 2017
Region

Alessandra just learned in algebra class about the values of E and PI, where E is the base of the natural logarithms, and PI is the ratio of the circumference of a circle to its diameter.
She also discovered that depending on how you store it in a program, the precision of the output is different, and decided to write a program to demonstrate that.
See if you can do that with this problem.

Input: None
Output: Write a program that displays the four values you see here: two different precision values each of the math constants E and PI.

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Alessandra
{
	public static void main(String [] args) throws IOException
	{
		double ed = Math.E;
		float ef = (float)Math.E;
		double pid = Math.PI;
		float pif = (float)Math.PI;
		out.println(ef);
		out.println(ed);
		out.println(pif);
		out.println(pid);
	}
}
/*

Output
2.7182817
2.718281828459045
3.1415927
3.141592653589793

*/