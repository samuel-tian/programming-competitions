import java.io.*;
import java.util.*;

public class Freshener {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("freshener.dat"));
        int numSets = s.nextInt();
        s.nextLine();

        for(int i = 1; i <= numSets; i++){
            int rows = s.nextInt();
            int cols = s.nextInt();
            s.nextLine();
            char[][] room = getRoom(rows, cols, s);
            int[][] numFragrance = initFresheners(room);
            spread(room, numFragrance);
            int[] result = getResults(numFragrance);
            System.out.println(result[0] + " " + result[1]);
//            if(i == 13)
//                show(numFragrance);
        }
        s.close();
    }

    private static void show(int[][] m) {
        for(int r = 0; r < m.length; r++){
            for(int c = 0; c < m[0].length; c++)
                System.out.print(m[r][c]);
            System.out.println();
        }

    }

    private static void spread(char[][] room, int[][] numFragrance) {
        String nonDigits = "*-|";
        for(int r = 0; r < room.length; r++)
            for(int c = 0; c < room[0].length; c++){
                char ch = room[r][c];
                if(!nonDigits.contains(ch + "")) {
                    int range = (int) (ch - '0');
                    spreadOne(room, numFragrance, r, c, range, new boolean[room.length][room[0].length]);
                }
            }
    }

    private static void spreadOne(char[][] room, int[][] numFragrance, int r,
            int c, int range, boolean[][] beenHere) {
        if(!inRange(r, c, room) || isWall(r, c, room))
            return;
        if(!beenHere[r][c])
            numFragrance[r][c]++;
        beenHere[r][c] = true;
        if(range > 0) {
            range--;
            spreadOne(room, numFragrance, r + 1, c, range, beenHere);
            spreadOne(room, numFragrance, r - 1, c, range, beenHere);
            spreadOne(room, numFragrance, r, c + 1, range, beenHere);
            spreadOne(room, numFragrance, r, c - 1, range, beenHere);
        }

    }

    private static boolean isWall(int r, int c, char[][] room) {
       char ch = room[r][c];
       return ch == '-' || ch == '|';
    }

    private static boolean inRange(int r, int c, char[][] room) {
        return 0 <= r && r < room.length && 0 <= c && c < room[0].length;
    }

    private static int[] getResults(int[][] numFragrance) {
        int[] result = new int[2];
        for(int r = 0; r < numFragrance.length; r++)
            for(int c = 0; c < numFragrance[0].length; c++)
                if(numFragrance[r][c] > 1)
                    result[0]++;
                else if(numFragrance[r][c] == 0)
                    result[1]++;
        return result;
    }

    private static int[][] initFresheners(char[][] room) {
        int[][] result = new int[room.length][room[0].length];
        for(int r = 0; r < room.length; r++)
            for(int c = 0; c < room[0].length; c++){
                char ch = room[r][c];
                if(ch == '-' || ch == '|')
                    result[r][c] = -1;
            }
        return result;
    }

    private static char[][] getRoom(int rows, int cols, Scanner s) {
        char[][] result = new char[rows][cols];
        String validChars = "*-|0123456789";
        for(int r = 0 ; r < rows; r++) {
            String rowData = s.nextLine();
            assert rowData.length() == cols;
            for(int c = 0; c < rowData.length(); c++){
                result[r][c] = rowData.charAt(c);
                assert validChars.contains(result[r][c] + "");
            }
        }
        return result;
    }
}