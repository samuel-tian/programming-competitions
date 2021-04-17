import java.io.File;
import java.io.FileNotFoundException;
import java.util.Comparator;
import java.util.Scanner;
import java.util.TreeMap;

public class students {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner file = new Scanner(new File("students.dat"));
		int cases = file.nextInt();
		file.nextLine();
		while(cases-->0)
		{
			int st = file.nextInt();
			TreeMap<Integer, String> map = new TreeMap<>(new Comparator<Integer>() {
				@Override
				public int compare(Integer a, Integer b) {
					return b-a;
				}
			});
			while(st-->0)
			{
				String name = file.next();
				int grade = file.nextInt();
				map.put(grade, name);
			}
			
			for (Integer i : map.keySet()) {
				System.out.println(map.get(i)+" "+i);
			}
			if(cases>0){
			System.out.println();
			}
			
			
			
		}

	}

}
