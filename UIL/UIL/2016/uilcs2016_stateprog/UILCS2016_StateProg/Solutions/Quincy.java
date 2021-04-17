import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * 
 * @author sno
 * 
 * Given an (the pre, in and post) unbalance tree and a specification for rotations,
 * Show the inorder, preordered, and post ordered traversal of the new tree.
 * 
 *
 */
public class Quincy {

	public static void main(String [] args) throws FileNotFoundException {
		Scanner f = new Scanner(new File("quincy.dat"));
		int N = f.nextInt(); f.nextLine();
		while(N-- > 0) {
			String line = f.nextLine();
			Scanner q = new Scanner(line);
			QuincyNode root = new QuincyNode(q.next());
			boolean balanced = true;
			while(q.hasNext()) {
				String inputNodeVal = q.next();
				root.insert(inputNodeVal);
				root.recalculateHeight();
				//root.print();
				String reason = root.checkRotation();
				if(reason != null) {
					System.out.println("TREE IS UNBALANCED AFTER " + inputNodeVal + ", MUST PERFORM A " + reason + " AT ROOT TO REBALANCE.");
					balanced = false;
					break;
				}
			}
			if(balanced) {
				System.out.println("TREE IS BALANCED.");
			}
		}
	}
}
class QuincyNode {
	public QuincyNode left;
	public QuincyNode right;
	public int subTreeHeight;
	public String data;
	public QuincyNode(String data) {
		this.data = data;
	}
	//should really only be called on root node
	public void insert(String val) {
		if(val.compareTo(this.data) > 0 && this.right == null) {
			this.right = new QuincyNode(val);
		} else if(val.compareTo(this.data) <= 0 && this.left == null) {
			this.left = new QuincyNode(val);
		} else if(val.compareTo(this.data) > 0) {
			this.right.insert(val);
		} else {
			this.left.insert(val);
		}
		
	}
	//should really only be called on root node
	public void recalculateHeight() {
		if(this.left == null && this.right == null) {
			this.subTreeHeight = 1;
		} else {
			if(this.left != null ) {
				this.left.recalculateHeight();
			}
			if(this.right != null) {
				this.right.recalculateHeight();
			}
			if(this.left == null) {
				this.subTreeHeight = this.right.subTreeHeight + 1;
			} else if(this.right == null) {
				this.subTreeHeight = this.left.subTreeHeight + 1;
			} else {
				this.subTreeHeight = (this.left.subTreeHeight > this.right.subTreeHeight) ? this.left.subTreeHeight + 1: this.right.subTreeHeight + 1;
			}
		}
		
	}
	public void print() {
		String leftVal = this.left == null ? "null" : this.left.data;
		String rightVal = this.right == null ? "null" : this.right.data;
		System.out.println("Node: \"" + this.data + "\" \theight: " + this.subTreeHeight +  " \tleft: " + leftVal + " \tright: " + rightVal);
		
		if(this.left != null) {
			this.left.print();
		}
		
		if(this.right != null) {
			this.right.print();
		}
	}
	// should only be called on the root node
	/*
	 * 1 == 
	 */
	public String checkRotation() {
		int leftHeight = this.left == null ? 0: this.left.subTreeHeight;
		int rightHeight = this.right == null ? 0 : this.right.subTreeHeight;
		if(rightHeight - leftHeight >= 2) {
			int rightLeftHeight = this.right.left == null ? 0: this.right.left.subTreeHeight;
			int rightRightHeight = this.right.right == null ? 0: this.right.right.subTreeHeight;
			if(rightLeftHeight - rightRightHeight >= 1) {
				return "DOUBLE LEFT ROTATION";
			} else {
				return "SINGLE LEFT ROTATION";
			}
		} else if (leftHeight - rightHeight >= 2) {
			int leftLeftHeight = this.left.left == null ? 0: this.left.left.subTreeHeight;
			int leftRightHeight = this.left.right == null ? 0: this.left.right.subTreeHeight;
			if(leftRightHeight - leftLeftHeight >= 1) {
				return "DOUBLE RIGHT ROTATION";
			} else {
				return "SINGLE RIGHT ROTATION";
			}
		}
		return null;
	}
}
