import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.TreeMap;

import javax.script.ScriptException;

public class number {
	static TreeMap<Integer, String> map;

	public static void main(String[] args) throws FileNotFoundException, ScriptException {
		Scanner file = new Scanner(new File("number.dat"));

		long cases = file.nextLong();
		file.nextLine();
		map = new TreeMap<>();

		map.put(1000, "M");
		map.put(900, "CM");
		map.put(500, "D");
		map.put(400, "CD");
		map.put(100, "C");
		map.put(90, "XC");
		map.put(50, "L");
		map.put(40, "XL");
		map.put(10, "X");
		map.put(9, "IX");
		map.put(5, "V");
		map.put(4, "IV");
		map.put(1, "I");

		while (cases-- > 0) {
			System.out.println(trans(file.nextInt()));
		}

	}

	public static String trans(int v) {
		if (map.floorKey(v) == v) {
			return map.get(v);
		}
		return map.get(map.floorKey(v)) + trans(v - map.floorKey(v));
	}

}
