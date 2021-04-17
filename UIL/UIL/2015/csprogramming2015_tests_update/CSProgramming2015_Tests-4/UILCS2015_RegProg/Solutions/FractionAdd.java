import java.util.*;
import java.io.*;



public class FractionAdd {
	public static boolean DEBUG = false;
	public static void main (String [] args) throws IOException {
	        File inFile = new File ("fractionadd.dat");
		Scanner cons = new Scanner (inFile);
		int t = cons.nextInt();
		cons.nextLine();
		while (t-- > 0) {
			String sf = cons.nextLine();
			Fraction [] fs = getFractions(sf);
			if (fs[0].compare(fs[1]) == 0) 
				System.out.println(fs[0] + " = " + fs[1]);
			if (fs[0].compare(fs[1]) > 0) 
				System.out.println(fs[0] + " > " + fs[1]);
			if (fs[0].compare(fs[1]) < 0) 
				System.out.println(fs[0] + " < " + fs[1]);
		}				
	}	
	
	public static Fraction [] getFractions (String s) {
		s = s.replaceAll("/", " ");
		if (DEBUG) System.out.println(s);
		s = s.replaceAll("\\+", " ");
		if (DEBUG) System.out.println(s);
		int operatorPosn = s.indexOf("?");
		String first = s.substring(0, operatorPosn);
		String second = s.substring(operatorPosn + 1);
		
		Scanner scn = new Scanner(first);
		Fraction f1 = new Fraction(0, 1);
		while (scn.hasNext()) {
			f1 = f1.add(new Fraction(scn.nextInt(), scn.nextInt()));
		}
		scn = new Scanner(second);
		Fraction f2 = new Fraction(0, 1);
		while (scn.hasNext()) {
			f2 = f2.add(new Fraction(scn.nextInt(), scn.nextInt()));
		}
		Fraction[] fs = {f1, f2};
		return fs;		
	}
	
}

class Fraction {
	int n = 0;
	int d = 1;
	
	public Fraction (int n, int d) {
		this.n = n; this.d = d;
	}
	
	public Fraction add (Fraction other) {
		int num = n*other.d + d*other.n;
		int den = d*other.d;
		int gcd = gcd(num, den);
		return new Fraction(num/gcd, den/gcd);
	}
	
	public String toString () {
		return n + "/" + d;
	}
	
	public int compare (Fraction other) {
		int n1 = this.n*other.d;
		int n2 = other.n*this.d;
		if (n1 == n2) return 0;
		return (n1 > n2 ? 1: -1);
	}
	
	// Calculate GCD
	public int gcd(int p, int q) {
		if (q == 0) {
			return p;
		}	
		return gcd(q, p % q);
	}		
}
