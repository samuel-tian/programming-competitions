import java.util.Scanner;
import java.io.File;

import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.TreeSet;
import java.util.Comparator;


public class Junk {
	public static void main(String[] args) throws Exception {
		Scanner fin = new Scanner(new File("junk.dat"));
		
		int n = fin.nextInt();
		fin.nextLine();
		
		Map<String, Set<Satellite>> byMass = new HashMap<>();
		Map<String, Set<Satellite>> byDate = new HashMap<>();
		
		for (int i = 0; i < n; i++) {
			Satellite sat = new Satellite();
			
			String[] line = fin.nextLine().split("\\t");
			
			sat.name = line[0];
			sat.mass = Integer.parseInt(line[2]);
			
			String[] dateParts = line[3].split("/");
			sat.mmddyyyy = line[3];
			sat.yyyymmdd = dateParts[2] + dateParts[0] + dateParts[1];			
			
			if (!byMass.containsKey(line[1])) {
				byMass.put(line[1], new TreeSet<>(new MassComparator()));
				byDate.put(line[1], new TreeSet<>(new DateComparator()));
			}
			byMass.get(line[1]).add(sat);
			byDate.get(line[1]).add(sat);
		}
		
		n = fin.nextInt();
		fin.nextLine();

		for (int i = 0; i < n; i++) {
			String[] task = fin.nextLine().split(":");
						
			if (task[1].equals("MASS")) { System.out.println(byMass.get(task[0])); }
			else { System.out.println(byDate.get(task[0])); }
		}
		
		fin.close();
	}
	
	private static class Satellite {
		String name, mmddyyyy, yyyymmdd;
		int mass;
		
		public String toString() { return name; }
	}

	private static class DateComparator implements Comparator<Satellite> {
		public int compare(Satellite one, Satellite two) {
			return two.yyyymmdd.compareTo(one.yyyymmdd);
		}
	}

	private static class MassComparator implements Comparator<Satellite> {
		public int compare(Satellite one, Satellite two) {
			return two.mass - one.mass;
		}
	}
}