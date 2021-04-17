import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class sort 
{

	public static void main(String[] args) throws FileNotFoundException 
	{
		Scanner file = new Scanner(new File("sort.dat"));
		
		long cases = file.nextLong();
		file.nextLine();
		
		String pref = "kqrhbp";
		while(cases-->0)
		{
			String[] line = file.nextLine().split(" ");
			
			Arrays.sort(line, new Comparator<String>() {

				@Override
				public int compare(String a, String b) {
					
					if(a.charAt(0)>=97 && b.charAt(0) >= 97 || a.charAt(0)<97 && b.charAt(0)< 97 )
					{
						a = a.toLowerCase();
						b = b.toLowerCase();
						
						int d = pref.indexOf(a);
						int c = pref.indexOf(b);
						
						if(d<c)
						{
							return 1;
						}
						else if(d>c)
						{
							return -1;
						}
						else
						{
							return 0;
						}
						
					}
					else
					{
						if(a.charAt(0)<97)
						{
							return 1;
						}
						else
						{
							return -1;
						}
					}
				}
			});
			
			System.out.println(Arrays.toString(line).replaceAll("[\\[\\]\\,]", "").trim());
			
			
		}

	}

}
