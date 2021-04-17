import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import javax.script.ScriptException;

public class robbery {

	public static void main(String[] args) throws FileNotFoundException, ScriptException 
	{
		Scanner file = new Scanner(new File("robbery.dat"));
		
		long cases = file.nextLong();
		file.nextLine();
		while(cases-->0)
		{
			int maxWeight = file.nextInt();
			int num = file.nextInt();
			
			int[] price = new int[num+1];
			int[] weight = new int[num+1];
			
			for (int i = 1; i < weight.length; i++) {
				price[i] = file.nextInt();
				
			}
			
			for (int i = 1; i < weight.length; i++) {
				weight[i] = file.nextInt();
				
			}
			
			long[][] mat = new long[num+1][maxWeight+1];
			
			for (int i = 0; i < mat.length; i++) {
				for (int j = 0; j < mat[0].length; j++) {
					if(i==0||j==0)
					{
						
					}
					else if(j>=weight[i])
					{
						mat[i][j] =  Math.max(mat[i-1][j], mat[i-1][(j-weight[i])]+price[i]);
					}
					else
					{
						mat[i][j] = mat[i-1][j];
					}
				}
			}
			System.out.println(mat[mat.length-1][mat[0].length-1]);
		}

	}

}
