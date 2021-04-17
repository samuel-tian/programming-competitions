import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Scanner;

import javax.script.ScriptException;

public class rook 
{

	public static void main(String[] args) throws FileNotFoundException, ScriptException 
	{
		
		Scanner file = new Scanner(new File("rook.dat"));
		
		long cases = file.nextLong();
		file.nextLine();
		while(cases-->0)
		{
			int num = file.nextInt();
			ArrayList<loc> locations = new ArrayList<>();
			
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					locations.add(new loc(i,j));
				}
			}
			
			ArrayList<loc> in = new ArrayList<>();
			
			while(num-->0)
			{
				int poz = file.nextInt();
				int r = (poz-1)/8;
				int c = (poz-1)%8;
				in.add(new loc(r,c));
			}
			
			for (loc l : in) {
				for(int xd = locations.size()-1; xd>=0; xd--)
				{
					loc y = locations.get(xd);
					if(y.r==l.r||y.c==l.c)
					{
						locations.remove(xd);
					}
				}
			}
			
			System.out.println(locations.size());
			
			
		}

	}
	
	static class loc
	{
		int r, c;
		public loc(int r, int c)
		{
			this.r=r;
			this.c=c;
		}
	}

}
