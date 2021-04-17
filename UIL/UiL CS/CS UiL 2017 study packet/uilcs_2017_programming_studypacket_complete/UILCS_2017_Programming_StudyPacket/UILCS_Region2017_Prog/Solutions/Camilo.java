/*
UIL 2017 - Camilo
Region

Camilo is fascinated with patterns and has come up with one that he thinks is interesting. Using a single integer value, he creates an asymmetrical arrow shape. 

Study it carefully and see if you can write a program to create these shapes.

Input: Several integers N, such that 3 <= N <= 20, each on one line.

Output: For each integer N, an asymmetrical arrow shape as shown below, relative in size to the value N. A blank line will follow each arrow shape.

Sample Input: 
3
4
5

Sample Output: 
*
**
***
****
***
*

*
**
***
****
*****
***
*

*
**
***
****
*****
******
*****
***
*

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Camilo
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("camilo.dat"));
		Scanner k = new Scanner(in);
		while(f.hasNext())
		{
			int n = f.nextInt();
			for(int r = 0;r<=n;r++)
			{
				for(int c=0;c<=r;c++)
					out.print("*");
				out.println();
			}
			for(int r = (n%2==0?n-2:n-1);r>=0;r-=2)
			{
				for(int c=0;c<=r;c++)
					out.print("*");
				out.println();
			}
				out.println();
		}
	}
}
/*
Test input:
3
4
5
6
7
10
13
14

Output
*
**
***
****
***
*

*
**
***
****
*****
***
*

*
**
***
****
*****
******
*****
***
*

*
**
***
****
*****
******
*******
*****
***
*

*
**
***
****
*****
******
*******
********
*******
*****
***
*

*
**
***
****
*****
******
*******
********
*********
**********
***********
*********
*******
*****
***
*

*
**
***
****
*****
******
*******
********
*********
**********
***********
************
*************
**************
*************
***********
*********
*******
*****
***
*

*
**
***
****
*****
******
*******
********
*********
**********
***********
************
*************
**************
***************
*************
***********
*********
*******
*****
***
*

*/