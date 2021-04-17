import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class sudoku {

	static int mat[][];
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner file = new Scanner(new File("sudoku.dat"));
		int cases = file.nextInt();
		file.nextLine();
		while(cases-->0)
		{
			mat = new int[9][9];
			for(int i =0;i<mat.length;i++)
			{
				String[] in = file.nextLine().split(" ");
				for (int j = 0; j < in.length; j++) {
					mat[i][j] = Integer.parseInt(in[j]);
				}
			}
			if(file.hasNextLine())
			{
				file.nextLine();
			}
			
			solve();
			
			for (int i = 0; i < mat.length; i++) {
				System.out.println(Arrays.toString(mat[i]).replaceAll("[\\[\\],]", ""));
			}
			if(cases>0){
				System.out.println();	
			}
			
		}

	}
	
	static boolean solve()
	{
		
		for (int r = 0; r < mat.length; r++) 
		{
			for (int c = 0; c < mat.length; c++) 
			{
				if(mat[r][c]==0)
				{
					for (int i = 1; i <= 9; i++) 
					{
						mat[r][c] = i;
						if(ok(r, c, i) && solve())
						{
							return true;
							
						}
						else
						{
							mat[r][c] = 0;		
						}
					}
					return false;
				}
			}
		}
		
		return true;
	}
	
	static boolean ok(int r, int c, int k)
	{
		for (int i = 0; i < mat.length; i++) {
			if(i!=r && mat[i][c]==k)
			{
				return false;
			}
			if(i!=c && mat[r][i]==k)
			{
				return false;
			}
		}
		
		TreeSet<Integer> x = new  TreeSet();
		x.add(0);
		x.add(3);
		x.add(6);
		x.add(9);
		
		int lr = x.floor(r);
		int ur = x.ceiling(r);
		int lc = x.floor(c);
		int uc = x.ceiling(c);
		
		for (int i = lr; i < ur; i++) {
			for (int j = lc; j < uc; j++) {
				if(r!=i && c!= j && mat[i][j]==k)
				{
					return false;
				}
			}
		}
		
		return true;
	}
	
}
