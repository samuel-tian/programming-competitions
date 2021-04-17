import java.util.Scanner;
import java.io.File;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;
import java.util.TreeSet;


public class AstroNot
{
	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(new File("astronot.dat"));
		
		int n = fin.nextInt();
		fin.nextLine();
		
		List<String> candidates = new ArrayList<>();
		Set<String> astronauts = new HashSet<>();
		
		for (int i = 0; i < n; i++) { candidates.add(fin.nextLine()); }
		
		int m = fin.nextInt();
		fin.nextLine();
		
		for (int i = 0; i < m; i++) {
			String[] names = fin.nextLine().split(" ");
			for (int j = 2; j < names.length; j++) {
				astronauts.add(names[j]);
			}
		}
		
		for (String candidate : candidates) {
			if (!astronauts.contains(candidate)) {
				System.out.println(candidate);
			}
		}
		
		fin.close();
	}
}