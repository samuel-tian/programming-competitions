import java.util.*;
import java.io.*;

public class Fractal {
	public static void main(String args[]) throws IOException {
		Scanner in = new Scanner(new File("fractal.dat"));

		int F = in.nextInt();

		for (int casenum = 1; casenum <= F; casenum++) {

			int R = in.nextInt();
			int T = in.nextInt();
			in.nextLine();

			System.out.printf("Fractal #%d:\r\n", casenum);

			Map<String, List<String>> rules = new HashMap<String, List<String>>();
			while (R-- > 0) {
				String line = in.nextLine();
				String[] split = line.split(" -> ");
				String S = split[0];
				split = split[1].split(" ");
				List<String> Sprime = new ArrayList<String>();
				for (String st : split) {
					Sprime.add(st);
				}
				rules.put(S, Sprime);
			}

			while (T-- > 0) {
				int N = in.nextInt();
				int X = in.nextInt();
				in.nextLine();
				List<String> cur = new ArrayList<String>();
				String line[] = in.nextLine().split(" ");
				for (String st: line) {
					cur.add(st);
				}
				while (X-- > 0) {
					List<String> next = new ArrayList<String>();
					for (String S : cur) {
						if (rules.containsKey(S)) {
							for (String s2 : rules.get(S)) {
								next.add(s2);
							}
						} else {
							next.add(S);
						}
					}
					cur = next;
				}
				for (int i = 0; i < cur.size(); i++) {
					if (i != 0) System.out.print(" ");
					System.out.print(cur.get(i));
				}
				System.out.println();
			}
		}

		in.close();
	}
}
