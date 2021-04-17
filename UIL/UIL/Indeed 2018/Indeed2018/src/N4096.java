import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Scanner;

import javax.script.ScriptException;

public class N4096 
{
	static String[][] board;
	
	public static void main(String[] args) throws FileNotFoundException, ScriptException 
	{
		Scanner file = new Scanner(new File("N4096.dat"));
		
		long cases = file.nextLong();
		file.nextLine();
		while(cases-->0)
		{
			
			board = new String[4][4];
			for (int i = 0; i < board.length; i++) {
				board[i]= file.nextLine().split(" ");
			}
			
			String dir = file.nextLine();
			
			switch (dir) {
			case "left":
				shiftLeftA();
				shiftLeftA();
				shiftLeftA();
				shiftLeft();
				shiftLeftA();
				shiftLeftA();
				shiftLeftA();
				break;
				
			case "right":
				
				revese();
				shiftLeftA();
				shiftLeftA();
				shiftLeftA();
				shiftLeft();
				shiftLeftA();
				shiftLeftA();
				shiftLeftA();
				revese();
				
				break;
			case "up":
				
				
				shiftUpA();
				shiftUpA();
				shiftUpA();
				shiftUp();
				shiftUpA();
				shiftUpA();
				shiftUpA();
				break;
			case "down":
				
				reveseU();
				shiftUpA();
				shiftUpA();
				shiftUpA();
				shiftUp();
				shiftUpA();
				shiftUpA();
				shiftUpA();
				reveseU();
				break;

			}
			
			for (String[] s : board) {
				System.out.println(Arrays.toString(s).replaceAll("[\\]\\[,]", "").trim());
			}
			
		}

	}
	
	
	public static void revese()
	{
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board.length/2; j++) 
			{
				String temp = board[i][j];
				board[i][j] = board[i][board.length-1-j];
				board[i][board.length-j-1] = temp;
			}
		}
	}
	
	public static void shiftLeftA()
	{
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board.length-1; j++) 
			{
				if(board[i][j].equals("*"))
				{
					board[i][j] = board[i][j+1];
					board[i][j+1]="*";
				}
				
			}
		}
	}
	
	public static void shiftLeft()
	{
		for (int i = 0; i < board.length; i++) {
			ArrayList<Integer> comb = new ArrayList<>();
			
			for (int j = 0; j < board.length-1; j++) 
			{
				if(board[i][j].equals(board[i][j+1])&& !board[i][j].equals("*"))
				{
					comb.add(j);
					j++;
				}
			}
			
			for (Integer x : comb) {
				board[i][x]= Integer.parseInt(board[i][x])*2+"";
				board[i][x+1]="*";
			}
			
		}
	}
	
	public static void shiftUp()
	{
		for (int i = 0; i < board.length; i++) {
			ArrayList<Integer> comb = new ArrayList<>();
			
			for (int j = 0; j < board.length-1; j++) 
			{
				if(board[j][i].equals(board[j+1][i])&& !board[j][i].equals("*"))
				{
					comb.add(j);
					j++;
				}
			}
			
			for (Integer x : comb) {
				board[x][i]= Integer.parseInt(board[x][i])*2+"";
				board[x+1][i]="*";
			}
			
		}
	}
	
	public static void shiftUpA()
	{
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board.length-1; j++) 
			{
				if(board[j][i].equals("*"))
				{
					board[j][i] = board[j+1][i];
					board[j+1][i]="*";
				}
				
			}
		}
	}
	
	public static void reveseU()
	{
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board.length/2; j++) 
			{
				String temp = board[j][i];
				board[j][i] = board[board.length-1-j][i];
				board[board.length-j-1][i] = temp;
			}
		}
	}


}
