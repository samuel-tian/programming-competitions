import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

public class math 
{

	public static void main(String[] args) throws FileNotFoundException, ScriptException 
	{
		Scanner file = new Scanner(new File("math.dat"));
		
		long cases = file.nextLong();
		file.nextLine();
		while(cases-->0)
		{
			String a = file.nextLine();
			ScriptEngineManager manager = new ScriptEngineManager();
	        ScriptEngine engine = manager.getEngineByName("JavaScript");
	        
	        StringBuilder b = new StringBuilder(a);
	        
	        for (int i = 0; i < b.length()-1; i++) {
				if(b.charAt(i)=='-'&&b.charAt(i+1)=='-')
				{
					b.replace(i, i+2, "+");
				}
				
			}
	        a = b.toString();
	        
	        engine.eval("var n = "+a+";"
	        		+ "n = n.toFixed(2);"
	        		+ "print(n);");
	        
	       
		}

	}

}
