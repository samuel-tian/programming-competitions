/**
Benjamin has decided to expand the stack and queue process he just learned in class by adding some new processing features.
Besides the normal push and pop, he adds a low, middle, and high process, either inserting a value or removing a value using these concepts.
For this process, the middle of a list with an even numbered size will be the left value of the middle pair in the list. 
For example, in the list of values 5 3 7 6 1 9 8 7, the middle value is the 6, not the 1.

In a stack, he decides on eight operations, which are as follows:
1. P - Pop a value from the top of the stack.
2. P(X) - Push the value X to the top of the stack.
3. L - Remove the least value from the stack.
4. L(X) - Insert X immediately below the least value of the stack.
5. H - Remove the greatest value from the stack.
6. H(X) - Insert X immediately above the greatest value of the stack.
7. M - Remove the middle value of the stack.  
8. M(X) - Insert X so that becomes the new middle value of the stack.

For a queue, he will use the same eight operations, defined below:
1. P - Pop a value from the front of the queue.
2. P(X) - Push the value X to the back of the queue.
3. L - Remove the least value from the front of the queue.
4. L(X) - Insert X immediately in front of the least value of the queue.
5. H - Remove the greatest value from the queue.
6. H(X) - Insert X immediately behind the greatest value of the queue.
7. M - Remove the middle value of the queue.  
8. M(X) - Insert X so that becomes the new middle value of the queue.

Input - An initial string of digits in the range 0-9, all on the first line, with single space separation. The values in this list are to be used to create both a stack and a queue.
On the next several lines will be commands that will either affect the stack or the queue, with the letter S or Q, followed by one or more commands as defined above.

Output - Apply each command line, and then output the resulting list, as shown below, with the corresponding letter followed by the list of resulting values.

Sample data:
5 3 7 6 1 9 8 7
S P 
Q P(4)
Q L M(2)
S L(0) H(2)
S L M

Sample Output:
S [5, 3, 7, 6, 1, 9, 8]
Q [5, 3, 7, 6, 1, 9, 8, 7, 4]
Q [5, 3, 7, 6, 2, 9, 8, 7, 4]
S [5, 3, 7, 6, 0, 1, 9, 2, 8]
S [5, 3, 7, 1, 9, 2, 8]

 */
import java.io.File;
import java.io.FileNotFoundException;
import static java.lang.System.*;
import java.util.*;
public class Benjamin{
	public static void main(String [] args) throws FileNotFoundException {
		Scanner ff = new Scanner(new File("benjamin.dat"));
		String ss = ff.nextLine();
			args = ss.split(" ");
			ArrayList<Integer> s = new ArrayList();
			ArrayList<Integer> q = new ArrayList();
			for(int x = 0;x<args.length;x++){
				int n = Integer.parseInt(args[x]);
				s.add(n);
				q.add(n);
			}
			while(ff.hasNext()) {
			
			int t = s.size()-1;
			int f = 0;
			int b = q.size()-1;
			String com = ff.nextLine();
//			out.println(com);
			args=com.split(" ");
			if(args[0].equals("S"))
			{
				for(int x=1;x<args.length;x++)
					switch(args[x].charAt(0))
					{
						case 'P':if(args[x].length()==1)
								 	//pop from stack
								{
									s.remove(t);
									t--;
								}
								 else
								 	//push value to stack
								 {
								 	int n = args[x].charAt(2)-48;
								 	s.add(n);
								 	t++;
								 };break;
						case 'L':if(args[x].length()==1)
								 	//pop least value from stack
								{
									//find position of least value
									int l = 0;
									for(int i=1;i<s.size();i++)
										if(s.get(i)<s.get(l))
											l=i;
									s.remove(l);
									t--;
								}
								 else
								 	//push value below least value of stack
								 {
									//find position of least value
									int l = 0;
									for(int i=1;i<s.size();i++)
										if(s.get(i)<s.get(l))
											l=i;
								 	int n = args[x].charAt(2)-48;
								 	s.add(l,n);
								 	t++;
								 };break;
						case 'H':if(args[x].length()==1)
								 	//pop greatest value from stack
								{
									//find position of greatest value
									int l = 0;
									for(int i=1;i<s.size();i++)
										if(s.get(i)>s.get(l))
											l=i;
									s.remove(l);
									t--;
								}
								 else
								 	//push value above greatest value of stack
								 {
									//find position of greatest value
									int l = 0;
									for(int i=1;i<s.size();i++)
										if(s.get(i)>s.get(l))
											l=i;
								 	int n = args[x].charAt(2)-48;
								 	s.add(l+1,n);
								 	t++;
								 };break;
						case 'M':if(args[x].length()==1)
								 	//pop value from middle of stack
								{
									//find middle value of stack
									int m = t/2;
									s.remove(m);
									t--;
								}
								 else
								 	//push value to middle of stack
								 {
									//find middle value of stack
									int m = t%2==1?t/2+1:t/2;
								 	int n = args[x].charAt(2)-48;
								 	s.add(m,n);
								 	t++;
								 };break;
							
					}
					out.println("S "+s);
			}
			else
			{
				for(int x=1;x<args.length;x++)
					switch(args[x].charAt(0))
					{
						case 'P':if(args[x].length()==1)
								 	//pop from queue
								{
									q.remove(f);
									b--;
								}
								 else
								 	//push value to queue
								 {
								 	int n = args[x].charAt(2)-48;
								 	q.add(n);
								 	b++;
								 };break;
						case 'L':if(args[x].length()==1)
								 	//pop least value from queue
								{
									//find position of least value
									int l = 0;
									for(int i=1;i<q.size();i++)
										if(q.get(i)<q.get(l))
											l=i;
									q.remove(l);
									b--;
								}
								 else
								 	//push value in front of least value of queue
								 {
									//find position of least value
									int l = 0;
									for(int i=1;i<q.size();i++)
										if(q.get(i)<q.get(l))
											l=i;
								 	int n = args[x].charAt(2)-48;
								 	q.add(l,n);
								 	b++;
								 };break;
						case 'H':if(args[x].length()==1)
								 	//pop greatest value from queue
								{
									//find position of greatest value
									int l = 0;
									for(int i=1;i<q.size();i++)
										if(q.get(i)>q.get(l))
											l=i;
									q.remove(l);
									b--;
								}
								 else
								 	//push value behind greatest value of queue
								 {
									//find position of greatest value
									int l = 0;
									for(int i=1;i<q.size();i++)
										if(q.get(i)>q.get(l))
											l=i;
								 	int n = args[x].charAt(2)-48;
								 	q.add(l+1,n);
								 	b++;
								 };break;
						case 'M':if(args[x].length()==1)
								 	//pop value from middle of queue
								{
									//find middle position of queue
									int m = b/2;
									q.remove(m);
									b--;
								}
								 else
								 	//push value to middle of queue
								 {
									//find middle position of queue
									int m = b%2==1?b/2+1:b/2;
								 	int n = args[x].charAt(2)-48;
								 	q.add(m,n);
								 	b++;
								 };break;
							
					}
					out.println("Q "+q);
			}

			
		}
	}
}
/*
Test Data:
5 3 7 6 1 9 8 7
S P 
Q P(4)
Q L M(2)
S L(0) H(2)
S L M
Q P P P P(7)
S L(3) P H P L
S H(9) M(1)
Q P M(1) M(5)
S P M(6) M(5)
Q P(4) P H(3)
Q L(8) H L P P

Test Output:
S [5, 3, 7, 6, 1, 9, 8]
Q [5, 3, 7, 6, 1, 9, 8, 7, 4]
Q [5, 3, 7, 6, 2, 9, 8, 7, 4]
S [5, 3, 7, 6, 0, 1, 9, 2, 8]
S [5, 3, 7, 1, 9, 2, 8]
Q [6, 2, 9, 8, 7, 4, 7]
S [5, 3, 7, 3]
S [5, 3, 1, 7, 9, 3]
Q [2, 9, 8, 5, 1, 7, 4, 7]
S [5, 3, 6, 5, 1, 7, 9]
Q [9, 3, 8, 5, 1, 7, 4, 7, 4]
Q [5, 8, 7, 4, 7, 4]

*/