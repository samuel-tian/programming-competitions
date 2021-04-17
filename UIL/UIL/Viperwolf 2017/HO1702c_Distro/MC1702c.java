import java.util.*;

import static java.lang.System.*;


class MC1702c {
	
	public static void main(String[] args) {
		
		out.print("1) ");
		{
			int base1 = Integer.parseInt("16", 8);
			int base2 = Integer.parseInt("32", 16);
			int baseAns = base1 + base2;
			out.println("= " + base1 + " + " + base2);
			out.println("base-2: " + Integer.toString(baseAns, 2));
			out.println("base-8: " + Integer.toString(baseAns, 8));
			out.println("base-10: " + Integer.toString(baseAns, 10));
			out.println("base-16: " + Integer.toString(baseAns, 16));
			out.println("base-24: " + Integer.toString(baseAns, 24));
		}
		out.println();
		
		out.print("2) ");
		{
			double x = 0.1;
			int y = (int) 9.9;
			double z = (int) (x + y);
			out.println(z);
		}
		out.println();
		
		out.print("3) ");
		{
			String p = "+";
			char r = '"';
			out.println(p + "r" + 'p' + r + '+');
		}
		out.println();
		
		out.print("4) ");
		{
			String s = "abcabcabc";
			s.replaceAll("a", "c");
			s.replaceAll("cb", "a");
			out.println(s);
		}
		out.println();
		
		out.print("5) ");
		{
			int i = 0;
			boolean[] trueFalse = { false, true };
			boolean[] choices = new boolean[8];
			for (boolean P : trueFalse) {
				for (boolean Q : trueFalse ) {
					for (boolean R : trueFalse) {
						choices[i++] = P || !Q && R || !Q;
					}
				}
			}
			if (!choices[1]) { out.println("P = FALSE; Q = FALSE; R = TRUE"); }
			if (!choices[3]) { out.println("P = FALSE; Q = TRUE; R = TRUE"); }
			if (!choices[5]) { out.println("P = TRUE; Q = FALSE; R = TRUE"); }
			if (!choices[6]) { out.println("P = TRUE; Q = TRUE; R = FALSE"); }
			if (!choices[7]) { out.println("P = TRUE; Q = TRUE; R = TRUE"); }
		}
		out.println();
		
		out.print("6) ");
		{
			int alfa = 3;
			int bravo = 4;
			out.println(Math.ceil(alfa / bravo));
		}
		out.println();
		
		out.print("7) ");
		{
			int eger = 42;
			float ingPoint = 40.2f;
			short answer = (short) ingPoint;
			short erAnswer = answer;
			erAnswer /= 10 + 2;
			//erAnswer = erAnswer / ( (short)(10 + 2) );	//<-- equivalent code
			//erAnswer = (short)(erAnswer / 10 + 2);		//<-- not equivalent code
			eger += erAnswer;
			String ofText = "forty-two";
			out.println(eger + answer + ofText);
		}
		out.println();
		
		out.print("8) ");
		{
			int year = 2017;
			if (year % 4 != 0) { out.print("W"); }
			if (year % 4 == 0) { out.print("X"); }
			else if (year % 4 != 0) { out.print("Y"); }
			else { out.print("Z"); }
		}
		out.println();
		out.println();
		
		out.print("9) ");
		{
			String dijkstra = "Computer science is no" 
				+ "more about computers than astronomy"
				+ "is about telescopes.";
			String[] quote = dijkstra.split(" ");
			for (int i = 1; i < quote.length; i *= 2) {
			  out.print(quote[i] + " ");
			}
		}
		out.println();
		out.println();
		
		out.print("10) ");
		{
			String[] things = { "Dustin", "Eleven", 
								"Lucas", "Mike" };
			int x = Arrays.binarySearch(things, "Will");
			int strange = ~x;
			int stranger = strange + ~0;
			out.println(things[stranger]);
		}
		out.println();
		
		out.print("11) ");
		{
			String tale = "It was the best of times, ";
			tale += "it was the worst of times, ...";

			Scanner reader = new Scanner(tale);
			while (reader.hasNext()) {
				if (reader.next().length() > 3) {
					out.print(reader.next() + " ");
				}
			}
		}
		out.println();
		out.println();
		
		out.print("12) ");
		{
			boolean go = true;
			int tri = 1;
			while (go) {
				out.print(tri + " ");
				tri *= 3;
				if (tri / 2 < 100) { go = !go; }
				if (tri * 2 < 150) { go = !go; }
			}
		}
		out.println();
		out.println();
		
		out.print("13) ");
		{
			boolean one = 5 + 4 / 3 * 2 > 5 * 4 / 3 + 2;
			boolean two = one || !one && one;
			if (!two) {
				if (one) { out.print("A"); }
				else { out.print("B"); }
			}
			else if (one || two) {
				if (!two) { out.print("C"); }
				else { out.print("D"); }
			}
			else { out.print("E"); }
		}
		out.println();
		out.println();
		
		out.print("14) ");
		{
			char digit6 = '6';
			char digit8 = '8';
			char digit9 = '9';
			
//			<#1> temp = digit9 + digit8 + '.' + digit6;
			
/*			try {
				char[] temp = digit9 + digit8 + '.' + digit6;
				out.println("char[] (" + temp + ")"");
			}
			catch (Exception e) { } //*/
/*			try {
				String temp = digit9 + digit8 + '.' + digit6;
				out.println("String (" + temp + ")");
			}
			catch (Exception e) { } //*/
/*			try {
				char temp = digit9 + digit8 + '.' + digit6;
				out.println("char (" + temp + ")");
			}
			catch (Exception e) { } //*/
/*			try {
				Double temp = digit9 + digit8 + '.' + digit6;
				out.println("Double (" + temp + ")");
			}
			catch (Exception e) { } //*/
			try {
				int temp = digit9 + digit8 + '.' + digit6;
				out.println("int (" + temp + ")");
			}
			catch (Exception e) { } //*/
		}
		out.println();
		
		out.print("15) ");
		{
			List<String> cat = new ArrayList<>();
			cat.add("cat");
			List<String> dog = new LinkedList<>(cat);
			dog.add("dog");
			List<String> bird = new ArrayList<>(dog);
			bird.add("bird");
			out.println(bird.size());
/*
			out.println("cat = " + cat);
			out.println("dog = " + dog);
			out.println("bird = " + bird);
//*/
		}
		out.println();
		
		out.print("16) ");
		{
			int base = 127;
			base = base >> 6 << 8 >> 2 << 1;
			out.println(base);
		}
		out.println();
		
		out.print("17) ");
		{
			int[] d = { 3, 13, 11, 9, 12, 5 };
			try {
				int a = d[(d[0] + d[d.length - 1]) / 2];
				int b = d[0] + d[d[0]] - a;
				out.print(a / b);
				out.print(d[d[d[0]]]);
			} catch (RuntimeException re) {
				out.print("X");
			} catch (Exception e) {
				out.print("Y");
			} finally {
				out.print("Z");
			}
			out.println(d[d[0]]);
		}
		out.println();
		
		out.print("18) ");
		{
			int oneTwo = "one".compareTo("two");
			int twoThree = "two".compareTo("three");
			int threeOne = "three".compareTo("one");
			if (oneTwo < 0) { out.print("12 "); }
			if (twoThree < 0) { out.print("23 "); }
			if (threeOne < 0) { out.print("31"); }
		}
		out.println();
		out.println();
		
		out.print("19) ");
		{
			Stack<Character> left = new Stack<>();
			Stack<Character> right = new Stack<>();
			String text = "ABCD";
			for (int i = 0; i < text.length(); i++) {
				left.push(text.charAt(i));
				while (!right.isEmpty()) {
					left.push(right.pop());
				}
				right.addAll(left);
			}
			while (!left.isEmpty()) {
				out.print(left.pop());
			}
		}
		out.println();
		out.println();

		out.print("20) ");
		{
			String s = "JohnVonNeumann";
			char[] c = s.toCharArray();
			char max = Character.MIN_VALUE;
			char min = Character.MAX_VALUE;
			for (int i = 0; i < c.length; i++) {
				max = (char) Math.max(max, c[i]);
				min = (char) Math.min(c[i], min);
			}
			out.println((char) max + " " + (char) min);
		}
		out.println();

		out.print("21) ");
		{
			String regex = "d/\\w/\\s/\\w/\\d";
			String a = "1/a/ /b/2";
			String b = "3/x//y/4";
			String c = "5/q/_/p/d";
			String d = "d/0/ /_/2";
			String e = "d/\\w/\\s/\\w/\\d";
			
			if (a.matches(regex)) { out.println(a); }
			if (b.matches(regex)) { out.println(b); }
			if (c.matches(regex)) { out.println(c); }
			if (d.matches(regex)) { out.println(d); }
			if (e.matches(regex)) { out.println(e); }
		}
		out.println();
		
		out.print("22) ");
		{
			try {
//				String population = "27862596";
				String population = "27,862,596";
				double rateOfGrowth = 1.072;
				double projected = rateOfGrowth;
				projected *= Integer.parseInt(population);
				out.print((int) projected);
			} catch (Exception e) {
				out.println("No output due to an error. (" + e.toString() + ")");
			}
		}
		out.println();
		
		int[] x = { 4, 9, 8, 2, 5, 0, 9 };
		int y = 0;
		int z = x.length;
		
		out.print("23) ");
		{
			out.println(alpha(x, y, z)); 	//<#1> 
		}
		out.println();
		
		out.print("24) ");
		{
			out.print(Arrays.toString(x)); 	//<#2>
		}
		out.println();
		out.println();
		
		out.print("25) ");
		{
			out.println("Selection Sort");
		}
		out.println();
		
		out.print("26) ");
		{
			out.println("O(N^2)");
		}
		out.println();
		
		out.print("27) ");
		{
			out.println("Sequential Search");
		}
		out.println();
		
		out.print("28) ");
		{
			out.println("O(N)");
		}
		out.println();
		
		out.print("29) ");
		{
			out.println("Swap");
		}
		out.println();
		
		out.print("30) ");
		{
			out.println("O(1)");
		}
		out.println();
		
		out.print("31) ");
		{
			out.println(traverse("BAYAOSRJAECVL8E", "pre"));
		}
		out.println();
		
		out.print("32) ");
		{
			int[][] m = { { 7, 7, 9, 8, 3 }, 
										{ 1, 4, 2, 6, 9 }, 
										{ 3, 6, 1, 4, 8 } };
			int n = 0;
			for (int r = 0; r < m.length - 1; r++) {
				for (int c = 1; c < m[0].length; c++) {
					int s = m[r][c - 1] + m[r + 1][c - 1] + 
									m[r][c]     + m[r + 1][c];
					if (s > n) { n = s; }
				}
			}
			out.println(n);
		}
		out.println();
		
		Map<Character, Character> map;
		map = new TreeMap<>();
		String jack = "Jack_Sparrow";
		String kidd = "Captain_Kidd";
		for (int i = 0; i < kidd.length(); i++) {
			map.put(jack.charAt(i), kidd.charAt(i));
			map.put(kidd.charAt(i), jack.charAt(i));
		}
		
		out.print("33) ");
		{
			out.println(map.get(map.get('r')));	//<#1>
		}
		out.println();
		
		out.print("34) ");
		{
			out.println(map.size());	//<#2>
		}
		out.println();
		
		out.print("35) ");
		{
			out.println("3");
		}
		out.println();
		
		out.print("36) ");
		{
			out.println("3");
		}
		out.println();
		
		out.print("37) ");
		{
			out.println("Flip-flop");
		}
		out.println();
		
		out.print("38) ");
		{
out.println("Q && (P || !P)");
			boolean[] trueFalse = { false, true };
			boolean[] answers = { true, true, true, true, true };
			out.println("P Q  |  A B C D E");
			for (boolean P : trueFalse) {
				for (boolean Q : trueFalse) {
					int ansA = ( P && (Q || !Q) ) ? 1 : 0;
					int ansB = ( P && (Q || !P) ) ? 1 : 0;
					int ansC = ( P || !P && Q ) ? 1 : 0;
					int ansD = ( P || !Q && P ) ? 1 : 0;
					int ansE = ( Q && (P || !P) ) ? 1 : 0;
					out.println((P?1:0)+ " " + (Q?1:0) + "  |  " + ansA + " " + ansB + " " + ansC + " " + ansD + " " + ansE);
				}
			}
		}
		out.println();
		
		out.print("39) ");
		{
			String input = "(A - (B + C) * (D - E))";
			input = input.replaceAll("\\s", "");
			Stack<String> ops = new Stack<>();
			Stack<String> rpn = new Stack<>();
			
			for (int i = 0; i < input.length(); i++) {
				String c = input.substring(i, i+1);
				if (Character.isLetter(c.charAt(0))) { rpn.push(c); }
				else if (c.matches("[+\\-]")) {
					if (ops.peek().matches("[*/%]")) {
						String b = rpn.pop();
						String a = rpn.pop();
						rpn.push(a + " " + b  + " " + ops.pop());
					}
					ops.push(c);
				}
				else if (c.matches("[*/%]")) { ops.push(c); }
				else if (c.matches("[)]")) {
					while (!ops.peek().matches("[(]")) {
						String b = rpn.pop();
						String a = rpn.pop();
						rpn.push(a + " " + b + " " + ops.pop());
					}
					ops.pop();	// "("
				}
				else if (c.matches("[(]")) { ops.push(c); }
			}
			
			while (!ops.isEmpty()) {
				String op = ops.pop();
				if (op.matches("[+\\-*/%]")) {
					String b = rpn.pop();
					String a = rpn.pop();
					rpn.push(a + " " + b + " " + op);
				}
			}
			
			out.println(rpn.pop());
		}
		out.println();
	
		out.print("40) ");
		{
			byte n = -36;
			String bits = "00000000" + Integer.toBinaryString(n);
			bits = bits.substring(bits.length() - 8);
			out.println(bits);
		}
		out.println();
		
		
	}
	
	// For questions #23-28
	//-------------------------------------------------------
	static int alpha(int[] a, int b, int c) {
		int d = 0;
		for (int e = b; e < c; e++) {
			int f = beta(a, e, c);
			if (e != f) { d += gamma(a, e, f); }
		}
		return d;
	}

	static int beta(int[] a, int b, int c) {
		int d = b;
		for (int e = b; e < c; e++) {
			if (a[e] > a[d]) { d = e; }
		}
		return d;
	}

	static int gamma(int[] a, int b, int c) {
		int d = a[b];
		int e = a[c];
		a[b] = e;
		a[c] = d;
		return 1;
	}

	// For question #31
	//-------------------------------------------------------
	public static String traverse(String s, String order) {
	  if (s.length() == 0) return "";
	  int i = s.length() / 2;
	  char c = s.charAt(i);
	  String s1 = s.substring(0, i);
	  String s2 = s.substring(i+1);
	  if (order.equals("pre" )) { return c + traverse(s1, "pre") + traverse(s2, "pre"); } 
	  if (order.equals("post")) { return traverse(s1, "post") + traverse(s2, "post") + c; } 
	  if (order.equals( "in" )) { return traverse(s1, "in") + c + traverse(s2, "in"); } 
	  return "";
	}

}