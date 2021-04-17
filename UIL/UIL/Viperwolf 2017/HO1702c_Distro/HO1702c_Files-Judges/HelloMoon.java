import java.util.Scanner;
import java.io.File;

public class HelloMoon
{
	static int w, s, a, b, n;
	
	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(new File("hellomoon.dat"));
		
		String input = fin.nextLine();
		
		int r = Integer.parseInt(input.substring(1, 2));
		boolean pos = (input.charAt(3) == '+');
		
		int[] digits = new int[] { 21, 3, 25, 27, 23, 30, 28, 19, 29, 31 };
				
		if (r == 1) {
			w = 8;
			s = 0;
			a = 0;
			b = digits[input.charAt(4) - '0'];
			printHex();
			
			w = 7;
			s = pos ? 1 : 0;
			a = digits[input.charAt(5) - '0'];
			b = digits[input.charAt(6) - '0'];
			printHex();

			w = 6;
			s = pos ? 0 : 1;
			a = digits[input.charAt(7) - '0'];
			b = digits[input.charAt(8) - '0'];
			printHex();
		}
		else if (r == 2) {
			w = 5;
			s = pos ? 1 : 0;
			a = digits[input.charAt(4) - '0'];
			b = digits[input.charAt(5) - '0'];
			printHex();
			
			w = 4;
			s = pos ? 0 : 1;
			a = digits[input.charAt(6) - '0'];
			b = digits[input.charAt(7) - '0'];
			printHex();

			w = 3;
			s = 0;
			a = digits[input.charAt(8) - '0'];
			b = 0;
			printHex();
		}
		else {
			w = 3;
			s = 0;
			a = 0;
			b = digits[input.charAt(4) - '0'];
			printHex();
			
			w = 2;
			s = pos ? 1 : 0;
			a = digits[input.charAt(5) - '0'];
			b = digits[input.charAt(6) - '0'];
			printHex();

			w = 1;
			s = pos ? 0 : 1;
			a = digits[input.charAt(7) - '0'];
			b = digits[input.charAt(8) - '0'];
			printHex();
		}
		
		fin.close();
	}

	private static void printHex() {
		n = (w << 11) | (s << 10) | (a << 5) | b;
		String hex = "0000" + Integer.toHexString(n);
		System.out.println("0x" + hex.substring(hex.length() - 4));
	}
}