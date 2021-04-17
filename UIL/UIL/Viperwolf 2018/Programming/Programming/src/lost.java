import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class lost {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner file = new Scanner(new File("lost.dat"));
		int cases = file.nextInt();
		file.nextLine();
		while(cases-->0)
		{
			int rr = file.nextInt();
			int cc = file.nextInt();
			file.nextLine();
			char[][] mat = new char[rr][cc];
			int[] st = {0,0};
			for (int i = 0; i < mat.length; i++) {
				mat[i] = file.nextLine().toCharArray();
				for (int j = 0; j < mat[i].length; j++) {
					if(mat[i][j]=='S')
					{
						st = new int[]{i,j};
					}
				}
			}
			
			
			int steps = -1;
			Queue<Integer> q = new LinkedList<>();
			q.add(st[0]);
			q.add(st[1]);
			q.add(0);
			while(!q.isEmpty())
			{
				int r = q.poll();
				int c = q.poll();
				int str = q.poll();
				if(r>=0&&c>=0&&r<mat.length&&c<mat[0].length&&mat[r][c]!='#')
				{
					if(mat[r][c]=='E')
					{
						steps = str;
						break;
					}
					mat[r][c] = '#';
					q.add(r+1);q.add(c);q.add(str+1);
					q.add(r-1);q.add(c);q.add(str+1);
					q.add(r);q.add(c+1);q.add(str+1);
					q.add(r);q.add(c-1);q.add(str+1);
				}
			}
			System.out.println(steps==-1?"Not Possible":steps);
			
		}

	}
}
