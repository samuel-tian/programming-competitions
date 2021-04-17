import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Scanner;

import javax.script.ScriptException;

public class yes 
{

	public static void main(String[] args) throws FileNotFoundException, ScriptException 
	{
		Scanner file = new Scanner(new File("yes.dat"));
		
		long cases = file.nextLong();
		file.nextLine();
		while(cases-->0)
		{
			int votes = file.nextInt();
			
			Hashtable<String, String> voters = new Hashtable<>();
			
			while(votes-->0)
			{
				String name = file.next();
				String vo = file.next();
				voters.put(name, vo);
			}
			
			boolean c = false;
			
			int yes = 0;
			int no = 0;
			
			for (String s : voters.keySet()) {
				
				if(s.equals("caesar"))
				{
					System.out.println(voters.get(s).equals("Y")?"Yes":"No");
					c = true;
					break;
				}
				
				if(voters.get(s).equals("Y"))
				{
					yes++;
				}
				else
				{
					no++;
				}
				
			}
			
			if(!c)
			{
				System.out.println(yes>no?"YES":no>yes?"No":"Tie");
			}
			
		}

	}

}
