import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Espionage {
	
	public static final boolean DEBUG = false;
	public static void main (String[] args) throws IOException {
	        File inFile = new File ("espionage.dat");
		Scanner cons = new Scanner (inFile);
		int noOfTests = cons.nextInt();
		cons.nextLine();
		while (noOfTests-- > 0) {
			System.out.println(modulo(cons));
		}
	}

	public static int modulo(Scanner cons) {
		/*
		(an*10^n + ... + a1*10 + a0)%MODULO = (an*10^n)%MODULO + ... + (a1*10)%MODULO) + a0%MODULO.
		*/
		String inString = cons.nextLine();
		char [] inChars = inString.toCharArray();
		String digitString = "";
		
		for (int i = 0; i < inChars.length; i++) {
			int intVal = inChars[i];
			digitString += intVal;
		}
		int divisor = cons.nextInt();
		cons.nextLine();
		
		char [] digits = digitString.toCharArray();
		int answer = 0;
		for (int i = 0; i < digits.length; i++) {
			answer = (answer*10 + Integer.parseInt(digits[i] + ""))%divisor;
		}
		
		if (DEBUG) {
			System.out.println(digitString + "%" + divisor);	
			System.out.println(" = "  + answer + " Calculated");
			BigInteger inputInt = new BigInteger(digitString);
			System.out.println(" = " + inputInt.mod(new BigInteger(divisor + "")) + " BigInteger");
		}
		return answer;
	}
}
