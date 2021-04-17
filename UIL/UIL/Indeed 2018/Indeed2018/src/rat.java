import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

import javax.script.ScriptException;

public class rat 
{
	public static void main(String[] args) throws FileNotFoundException, ScriptException 
	{
		Scanner file = new Scanner(new File("rat.dat"));
		
		long cases = file.nextLong();
		file.nextLine();
		while(cases-->0)
		{
			int rr = file.nextInt();
			int cc = file.nextInt();
			file.nextLine();
			
			int sr = 0;
			int sc = 0;
			
			char[][] mat = new char[rr][cc];
			for (int i = 0; i < mat.length; i++) {
				mat[i] = file.nextLine().toCharArray();
				for (int j = 0; j < mat[i].length; j++) {
					if(mat[i][j]=='S')
					{
						sr=i;
						sc=j;
					}
				}
			}
			
			int min = Integer.MAX_VALUE;
			
			Queue<Integer> q = new LinkedList<>();
			q.add(sr);
			q.add(sc);
			q.add(0);
			
			while(!q.isEmpty())
			{
				int r = q.poll();
				int c = q.poll();
				int st = q.poll();
				
				if(r>=0&&c>=0&&r<mat.length&&c<mat[0].length&&mat[r][c]!='G')
				{
					if(mat[r][c]=='E')
					{
						min = st;
						break;
					}
					mat[r][c]='G';
					q.add(r+1);q.add(c);q.add(st+1);
					q.add(r-1);q.add(c);q.add(st+1);
					q.add(r);q.add(c+1);q.add(st+1);
					q.add(r);q.add(c-1);q.add(st+1);
				}
			}
			
			System.out.println(min==Integer.MAX_VALUE?"Oh Rem please help me":min+" seconds");
			
			
		}

	}

}
