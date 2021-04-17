
import java.io.*;
import java.util.*;


public class Marbles {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("marbles.dat"));
        int numSets = s.nextInt();
        s.nextLine();

        for(int i = 1; i <= numSets; i++){
            System.out.print("Data Set " + i);
            int rows = s.nextInt();
            int cols = s.nextInt();
            s.nextLine();
            char[][] board = new char[rows][cols];
            for(int r = 0; r < rows; r++){
                String temp = s.nextLine();
                for(int c = 0; c < cols; c++)
                    board[r][c] = temp.charAt(c);

            }
            int[] minMarblesLeft = {numMarblesOnBoard(board)};
            boolean solved = canBeSolved(board, minMarblesLeft);
            if(solved)
                System.out.println(" SOLVED");
            else
                System.out.println(" NOT SOLVED " + minMarblesLeft[0]);
        }
        s.close();
    }

    public static boolean canBeSolved(char[][] board, int[] minMarbles){
        //      printBoard(board);
        //      key.nextLine();
        int num = numMarblesOnBoard(board);
//        if(num < 3){
//            System.out.println(num);
//            showBoard(board);
//        }
        if(num < minMarbles[0])
            minMarbles[0] = num;
        // System.out.println(num);
        if(num == 1)
            return true;
        ArrayList<LegalMove> moves = getLegalMoves(board);
        // System.out.println(moves.size());
        for(LegalMove move : moves){
            //          System.out.println(move);
            // move marble and remove marble jumped over
            board[move.sourceRow()][move.sourceCol()] = 'o';
            board[move.destRow()][move.destCol()] = 'm';
            board[move.removedRow()][move.removeCol()] = 'o';
            if(canBeSolved(board, minMarbles))
                return true;
            // put them back to try other moves
            board[move.sourceRow()][move.sourceCol()] = 'm';
            board[move.destRow()][move.destCol()] = 'o';
            board[move.removedRow()][move.removeCol()] = 'm';
        }
        // tried all possiblities, none of them worked
        return false;
    }

    public static void printBoard(char[][] board){
        for(int r = 0; r < board.length; r++){
            for(int c = 0; c < board[r].length; c++)
                System.out.print(board[r][c] + " ");
            System.out.println();
        }
    }

    // pre: board != null, board is rectangular
    // post: returns the legal moves on board. If there are no legal
    // moves an ArrayList of size 0 is returned. board is not altered.
    public static ArrayList<LegalMove> getLegalMoves(char[][] board) {
        int[] rows = {-2, 0, 0, 2};
        int[] cols = {0, 2, -2, 0};
        int[] removeRows = {-1, 0, 0, 1};
        int[] removeCols = {0, 1, -1, 0};
        ArrayList<LegalMove> result = new ArrayList<LegalMove>();
        for(int r = 0; r < board.length; r++)
            for(int c = 0; c < board[0].length; c++)
                if(board[r][c] == 'm'){
                    for(int i = 0; i < rows.length; i++){
                        int newR = r + rows[i];
                        int newC = c + cols[i];
                        int rr = r + removeRows[i];
                        int rc = c + removeCols[i];
                        if(inbounds(newR, newC, board)
                                && board[newR][newC] == 'o'
                                    && board[rr][rc] == 'm'){

                            result.add(new LegalMove(new int[]{r, c, newR, newC, rr, rc}));
                        }
                    }
                }
        return result;
    }

    private static boolean inbounds(int r, int c, char[][] board){
        return r >= 0 && r < board.length && c >= 0 && c < board[0].length;
    }

    // pre: board != null, board is rectangular
    // post: return the number of m's in board
    public static int numMarblesOnBoard(char[][] board) {
        int num = 0;
        for(char[] row : board)
            for(char c : row)
                if(c == 'm')
                    num++;
        return num;
    }

    private static class LegalMove{
        private int[] coords;

        public String toString(){
            return Arrays.toString(coords);
        }

        public LegalMove(int[] vals){
            coords = Arrays.copyOf(vals, 6);
        }

        public int sourceRow() {
            return coords[0];
        }
        public int sourceCol() {
            return coords[1];
        }
        public int destRow() {
            return coords[2];
        }
        public int destCol() {
            return coords[3];
        }

        public int removedRow() {
            return coords[4];
        }

        public int removeCol() {
            return coords[5];
        }
    }

    public static void showBoard(char[][] board){
        for(char[] row : board){
            for(char c : row)
                System.out.print(c);
            System.out.println();
        }
    }
}
