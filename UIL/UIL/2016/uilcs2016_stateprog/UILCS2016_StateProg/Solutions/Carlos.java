/*
UIL State 2016, Carlos - Solution

Carlos has decided to write a program to simulate the poker game Five Card Draw, where he stores each card using a unique number, with the diamonds numbered from
1-13, hearts from 14-26, spades from 27-39, and clubs from 40-52. Card #1 is the Ace of Diamonds, and card #13 is the King of Diamonds,
#14 is the Ace of Hearts, and so on. Card #52 is the King of Clubs.

His program will input the ten numbers representing the cards alternately dealt to players A and B, and will tell him the best hand for each player, and which player wins the hand.
According to the rules of poker, the hand rankings are as follows, in order of best to worst.

FOUR OF A KIND - all four of the same card from each suit, like four 2s or four Kings.
FULL HOUSE - three of one kind and two of another, like three 8s and two Aces.
FLUSH - five cards, all of the same suit, like five spades or five diamonds, in no particular order.
STRAIGHT - five cards, of at least two different suits, all in a row, like Ace, 2, 3, 4, 5, or 10, Jack, Queen, King, Ace, or any 
sequence somewhere in the middle of the suit.  Wraparound sequences, like Queen, King, Ace, 2, 3, do not count as a straight.
THREE OF A KIND - three of one kind, like three 7s or three Jacks.
TWO PAIRS - 2 different pairs of the same kind, like two 5s and two 9s.
PAIR - one pair of the same kind, like two 4s or two Kings.
DUD HAND - Nothing good, for sure.

Input: Several poker hands of ten cards each, with the 1st, 3rd, 5th, 7th and 9th cards going to player A, and the others (2nd, 4th, 6th, 8th and 10th) to player B.
The ten cards will all be on one line, separated by single spaces, according to the description above.

Output: The best poker hand for each player's hand (Player A first, then Player B), and then state the winner of the hand. For the purposes of simplicity, it is guaranteed that there will be no ties.

Sample input:
32 18 6 44 19 7 22 21 23 38
1 34 14 13 27 26 29 39 42 52

Sample output:
THREE OF A KIND - PAIR - PLAYER A WINS
FULL HOUSE - FOUR OF A KIND - PLAYER B WINS
*/
import java.util.*;
import java.io.*;
import java.util.function.*;
import static java.lang.System.*;

class Carlos {
	static int[]handA,handB;
	static int[]kindA=new int[13],kindB=new int[13];
	static int[]suitA=new int[4],suitB=new int[4];

	public static void main(String...holdem) throws IOException{
		Scanner f = new Scanner(new File("carlos.dat"));
		while(f.hasNext()){
			holdem=f.nextLine().split(" ");
			handA=new int[5];
			handB=new int[5];
			kindA=new int[13];
			kindB=new int[13];
			suitA=new int[4];
			 suitB=new int[4];

			int a=0,b=0;
			for(int x=0;x<10;x+=2){
				handA[a++]=Integer.parseInt(holdem[x])-1;
				handB[b++]=Integer.parseInt(holdem[x+1])-1;
			}
			process(handA,kindA,suitA);
			process(handB,kindB,suitB);
			int A = hand(kindA,suitA);
			int B = hand(kindB,suitB);
			out.print(showHand(A)+" - "+showHand(B)+" - ");
			out.println(A>B?"PLAYER A WINS":"PLAYER B WINS");
			
		}
		
	}
	static String showHand(int x)
	{
		switch(x)
		{
			case 0:return "DUD HAND";
			case 1:return "PAIR";
			case 2:return "TWO PAIRS";
			case 3:return "THREE OF A KIND";
			case 4:return "STRAIGHT";
			case 5:return "FLUSH";
			case 6:return "FULL HOUSE";
			case 7:return "FOUR OF A KIND";
		}
		return "";
	}
			static int hand(int[]kind,int[]suit)
			{
			
			if(four(kind))
				return 7;
			else
			if(full(kind))
				return 6;
			else
			if(flush(suit))
				return 5;
			else
			if(straight(kind))
				return 4;
			else
			if(three(kind))
				return 3;
			else
			if(twoPair(kind))
				return 2;
			else
			if(pair(kind))
				return 1;
			else
				return 0;
			}
	static boolean four(int[]kind){
		for(int c:kind)
			if(c==4)
				return true;
		return false;
		}
	static boolean full(int[]kind){		
		boolean three=false,two=false;
		for(int c:kind)
			if(c==3)
				three=true;
		for(int c:kind)
			if(c==2)
				two=true;
		return three&&two;
}
	static boolean flush(int[]suit){		
		for(int c:suit)
			if(c==5)
				return true;
		return false;
}
	static boolean straight(int[]kind){
		String s="";
		for(int c:kind)
			s+=c;
		if(s.equals("1000000001111"))
			return true;
		return s.indexOf("11111")>=0;
		}
	static boolean three(int[]kind){
		for(int c:kind)
			if(c==3)
				return true;
		return false;
		}
	static boolean twoPair(int[]kind){
		boolean pair1=false,pair2=false;
		for(int c:kind)
			if(c==2)
				if(!pair1)
					pair1=true;
				else
					pair2=true;
		return pair1&&pair2;
		}
	static boolean pair(int[]kind){
		for(int c:kind)
			if(c==2)
				return true;
		return false;}

	static void process(int[]hand,int[]kind,int[]suit){
		Arrays.sort(hand);
		for(int c:hand)
			kind[c%13]++;
		for(int c:hand)
			suit[c/13]++;
	}
	
//	public boolean pair(){
//		
//	}
}

/*
Test data
32 18 6 44 19 7 22 21 23 38
1 34 14 13 27 26 29 39 42 52
8 21 36 51 48 28 30 33 35 39
4 43 30 23 36 20 3 17 29 45
2 40 3 41 17 43 31 44 45 46
11 3 24 5 50 7 36 9 40 12
6 2 19 3 32 4 10 5 23 1
2 40 30 28 3 16 41 4 17 31
27 7 52 22 25 21 50 23 10 38

Test output
THREE OF A KIND - PAIR - PLAYER A WINS
FULL HOUSE - FOUR OF A KIND - PLAYER B WINS
PAIR - DUD HAND - PLAYER A WINS
TWO PAIRS - PAIR - PLAYER A WINS
STRAIGHT - FLUSH - PLAYER B WINS
THREE OF A KIND - FLUSH - PLAYER B WINS
FULL HOUSE - FLUSH - PLAYER A WINS
TWO PAIRS - STRAIGHT - PLAYER B WINS
STRAIGHT - DUD HAND - PLAYER A WINS

*/