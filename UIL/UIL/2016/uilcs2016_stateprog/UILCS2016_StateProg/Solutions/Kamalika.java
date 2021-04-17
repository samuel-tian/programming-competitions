/**
Kamalika has always loved numbers and how seeing how different operations act on them.  
She has decided to do some simple research and needs your help writing the program to help with this.  
Her idea is to see how the resulting values from seven basic operations behave on two real number values 
A and B, specifically the resulting order in ascending value of the seven results.

For example, using the values 3 and 4, the sum is 7, difference is -1, product is 12, modulus is 3, 
quotient is 0.75, power A^B is 64, and B^A is 81.  Those values in ascending sorted order are: 

|Dif -1.00|Div  0.75|Mod  3.00|Sum  7.00|Prd 12.00|B^A 64.00|A^B 81.00|

However, for values less than 1, like 0.3 and 0.4, the order changes, like this:

|Dif -0.10|Prd  0.12|Mod  0.30|A^B  0.62|Sum  0.70|Div  0.75|B^A  0.76|

Input - Several pairs of real number values A and B, each in the range -5 <= value <= 5, excluding zero.

Output - Output the ascending order result of seven different mathematical operations as shown in 
the examples above, formatted EXACTLY as shown, with appropriate labels, followed by the corresponding 
resulting values rounded to the hundredths place. All results are guaranteed to be real, and to fit 
within the formatted spaces as shown in the examples.

Sample data:
3 4
.3 .4
3 .4
.3 4
-3 4
-4 3

Sample Output:
|Dif -1.00|Div  0.75|Mod  3.00|Sum  7.00|Prd 12.00|B^A 64.00|A^B 81.00|
|Dif -0.10|Prd  0.12|Mod  0.30|A^B  0.62|Sum  0.70|Div  0.75|B^A  0.76|
|B^A  0.06|Mod  0.20|Prd  1.20|A^B  1.55|Dif  2.60|Sum  3.40|Div  7.50|
|Dif -3.70|A^B  0.01|Div  0.08|Mod  0.30|Prd  1.20|B^A  1.52|Sum  4.30|
|Prd-12.00|Dif -7.00|Mod -3.00|Div -0.75|B^A  0.02|Sum  1.00|A^B 81.00|
|A^B-64.00|Prd-12.00|Dif -7.00|Div -1.33|Sum -1.00|Mod -1.00|B^A  0.01|

 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import static java.lang.System.*;
public class Kamalika {
	public static void main(String [] args) throws FileNotFoundException {
		Scanner f = new Scanner(new File("kamalika.dat"));
		while(f.hasNext()) {
			double a = f.nextDouble();
			double b = f.nextDouble();
			ArrayList<Val> list = new ArrayList<Val>();
			list.add(new Val(a+b,"Sum"));
			list.add(new Val(a-b,"Dif"));
			list.add(new Val(a*b,"Prd"));
			list.add(new Val(a/b,"Div"));
			list.add(new Val(a%b,"Mod"));
			list.add(new Val(Math.pow(a,b),"A^B"));
			list.add(new Val(Math.pow(b,a),"B^A"));
			Collections.sort(list);
			out.print("|");
			for(Val v:list)
				out.print(v+"|");
			out.println();
		}
	}
}
class Val implements Comparable<Val>
{
	double v;
	String lbl;
	Val(double v,String l){
		this.v=v;
		lbl=l;
	}
	public String toString()
	{
		return lbl+String.format("%6.2f",v);
	}
	public int compareTo(Val v)
	{
		if(this.v<v.v)return -1;
		if(this.v>v.v)return 1;
		return 0;
	}
}
/*
Test Data:
3 4
.3 .4
3 .4
.3 4
-3 4
-4 3
5 .2
2 .5
.1 .11

Test Output:
|Dif -1.00|Div  0.75|Mod  3.00|Sum  7.00|Prd 12.00|B^A 64.00|A^B 81.00|
|Dif -0.10|Prd  0.12|Mod  0.30|A^B  0.62|Sum  0.70|Div  0.75|B^A  0.76|
|B^A  0.06|Mod  0.20|Prd  1.20|A^B  1.55|Dif  2.60|Sum  3.40|Div  7.50|
|Dif -3.70|A^B  0.01|Div  0.08|Mod  0.30|Prd  1.20|B^A  1.52|Sum  4.30|
|Prd-12.00|Dif -7.00|Mod -3.00|Div -0.75|B^A  0.02|Sum  1.00|A^B 81.00|
|A^B-64.00|Prd-12.00|Dif -7.00|Div -1.33|Sum -1.00|Mod -1.00|B^A  0.01|
|B^A  0.00|Mod  0.20|Prd  1.00|A^B  1.38|Dif  4.80|Sum  5.20|Div 25.00|
|Mod  0.00|B^A  0.25|Prd  1.00|A^B  1.41|Dif  1.50|Sum  2.50|Div  4.00|
|Dif -0.01|Prd  0.01|Mod  0.10|Sum  0.21|A^B  0.78|B^A  0.80|Div  0.91|

*/