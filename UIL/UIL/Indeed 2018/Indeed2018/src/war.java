import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

public class war 
{

	public static void main(String[] args) throws FileNotFoundException, ScriptException 
	{
		Scanner file = new Scanner(new File("war.dat"));
		
		long cases = file.nextLong();
		file.nextLine();
		while(cases-->0)
		{
			int enemy_army = file.nextInt();
			file.nextLine();
			
			String[] m = file.nextLine().split(" ");
			int[] regiments = new int[m.length];
			
			for (int i = 0; i < regiments.length; i++) {
				regiments[i] = Integer.parseInt(m[i]);
			}
			
			boolean[] l = new boolean[enemy_army+1];
			l[0]=true;
			
			for(int i =0; i < regiments.length;i++)
			{
				for (int j = l.length-1; j >= regiments[i]; j--) {
					l[j]= l[j]||l[j-regiments[i]];
				}
			}
			
			System.out.println(l[l.length-1]?"HONOR":"DISHONOR");
			
	       
		}

	}

}
