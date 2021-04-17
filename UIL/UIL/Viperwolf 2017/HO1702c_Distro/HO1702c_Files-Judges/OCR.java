import java.util.Scanner;
import java.io.File;
import java.util.Set;
import java.util.TreeSet;


public class OCR
{
	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(new File("ocr.dat"));
		
		int n = fin.nextInt();
		int h = fin.nextInt();
		int w = fin.nextInt();
		
		String[][] cons = new String[n][h];
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) { cons[j][i] = fin.next(); }
		}
		
		int skyh = fin.nextInt();
		int skyw = fin.nextInt();
		fin.nextLine();
		
		Set<Integer> matches = new TreeSet<>();
		
		String[] sky = new String[skyh];
		for (int i = 0; i < skyh; i++) { sky[i] = fin.nextLine(); }
		
		for (int i = 0; i < n; i++) {
			for (int rotation = 0; rotation < 4; rotation++) {
				for (int y = 0; y <= skyh - cons[i].length; y++) {
					for (int x = 0; x <= skyw - cons[i][0].length(); x++) {
						boolean found = true;
						for (int r = 0; r < cons[i].length; r++) {
							for (int c = 0; c < cons[i][0].length(); c++) {
								if (cons[i][r].charAt(c) == '*' && 
								    sky[y+r].charAt(x+c) != '*') {
									found = false;
								}
							}
						}
						if (found) { matches.add(i+1); }
					}
				}
				
				String[] rotated = new String[cons[i][0].length()];
				for (int r = 0; r < rotated.length; r++) {
					rotated[r] = "";
					for (int c = cons[i].length - 1; c >= 0; c--) {
						rotated[r] += cons[i][c].charAt(r);
					}
				}
				cons[i] = rotated;
			}
		}
		
		for (int i : matches) { System.out.print(i + " "); }
		System.out.println();
		
		fin.close();
	}
}