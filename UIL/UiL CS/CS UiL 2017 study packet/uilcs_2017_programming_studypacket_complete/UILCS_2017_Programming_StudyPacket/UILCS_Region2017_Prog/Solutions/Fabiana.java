/*
UIL 2017 - Fabiana
Region

Fabiana has just learned about the depth concept as it relates to binary trees and decides to do some research with a binary search tree.
She takes a single word, picks a letter somewhere in the word, and finds the depth of where that letter settles in a binary search tree.
Doing it by hand is not difficult, but is time consuming, and she needs your help in writing a program to do it for her.

Given a single word with no spaces, followed by an integer P after a blank space, output the depth at which the letter in position P is inserted in a binary search tree.

Below is an example of a binary search tree formed by using the letters in the word REGIONUIL.
The first letter is always the root of the tree, and then each subsequent letter "finds" its place relative to the root, and any other nodes in the tree,
going to the left if its value is less than or equal to the current node, and going right if it is greater in value.

The root node that contains the letter R has a depth of zero, with the letters
E and U at level 1, G at level 2, and so on.

The data set consisting of the word REGIONUIL and the value 0 means find where the letter at position 0, the letter R, settles in the tree, which would be the root, or level 0.
The data set REGIONUIL 7 indicates the second occurrence of the letter I, which is at depth 4 in the tree shown below.

Depth levels
0    R
    / \
1  E   U
    \
2    G 
      \
3      I
      / \ 
4    I   O
         /
5       N
       / 
6     L

Input: A series of data sets, each on a separate line, consisting of a word (all uppercase) and an integer.

Output: The depth (or level) at which the indicated letter in the word settles in the binary search tree.

Sample Input: 
REGIONUIL 0
REGIONUIL 1
REGIONUIL 3
REGIONUIL 5
REGIONUIL 7

Sample Output:
0
1
3
5
4
 
*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Fabiana
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("fabiana.dat"));
		
		while(f.hasNext())
		{
			String s = f.next();
			BST t = new BST();//root
			int currentDepth = 0;
			int pos = f.nextInt();
			boolean flag = false;
			for(int x=0;x<s.length();x++){
				if(pos == x){
					flag = true;
//					out.print("Position:"+x);
				}
				else
					flag = false;
				t.insert(s.charAt(x), flag, currentDepth);
			}
//			t.inorder();
//			out.println();
		}
	}
}
class BSTNode{
	char data;
	BSTNode left,right;
	BSTNode(char l){
		data = l;
		left = null;
		right = null;
	}
}
class BST{
	BSTNode root;
	BST(){
		root = null;
	}
	//inorder traversal
	public void inorder()
     {
         inorder(root);
     }
	void inorder(BSTNode r)
     {
         if (r != null)
         {
             inorder(r.left);
             System.out.print(r.data +"-");
             inorder(r.right);
         }
     }
	//insert at root of tree
	void insert(char data, boolean f, int cD)
     {
         //call two-parameter insert method below to find proper place
         root = insert(root, data, f, cD);
     }
	//insert value at proper place in tree
	BSTNode insert(BSTNode node, char data, boolean f, int cD)
     {
         if (node == null){
             node = new BSTNode(data);
             if(f)
         		out.println(cD);
//         		out.println("Data = "+data+" :Depth = "+cD);
         }
         else
         {
             if (data <= node.data)
                 node.left = insert(node.left, data, f, cD+1);
             else
                 node.right = insert(node.right, data, f, cD+1);
         }
         return node;
     }
}
/*
Test input:
REGIONUIL 0
REGIONUIL 1
REGIONUIL 3
REGIONUIL 5
REGIONUIL 7
UIL 2
CONTEST 4
REGION 5
WINNER 3
INDIVIDUALTESTCHAMPION 14
PROGRAMMINGPACKETSWEPT 20

Test Output:
0
1
3
5
4
2
3
5
3
4
3

*/