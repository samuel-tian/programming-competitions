import java.util.Scanner;
import java.io.File;

public class Bully
{
	public static void main(String[] args) throws Exception
	{
		Scanner sc = new Scanner(new File ("bully.dat"));
		
		int T = sc.nextInt();

		while (T > 0)
		{
			int B = sc.nextInt();
			int R = sc.nextInt();	

			getAnswer(B, R);

			--T;
		}
	}

	public static void getAnswer(int B, int R)
	{
		int toysToBeDestroyed = 0;
		
		while (B > 0)
		{
			int destroyed_this_round = B / R * R; 		// Num toys destroyed that will def be resurrected
			if(destroyed_this_round == 0) 
				++destroyed_this_round; 				// Because remaining toys won't make new ones 
			int left_over = B - destroyed_this_round; 	// Always less than b, toys that weren't destroyed this "round"
			toysToBeDestroyed += destroyed_this_round;
			B = left_over + destroyed_this_round / R; 	// Set up the new round
		}
		
		System.out.println(toysToBeDestroyed);
	}
}