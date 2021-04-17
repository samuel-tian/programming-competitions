import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class Decisions {

    static int[] dr = {-1, 0, 1, 0}; // up, left, down, right
    static int[] dc = {0, -1, 0, 1};
    static int R, C;

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("decisions.dat"));
        int T = in.nextInt();
        outer:
        for (int i = 0; i < T; i++) {
            R = in.nextInt();
            C = in.nextInt();
            in.nextLine();
            char[][] mat = new char[R][C];
            List<Warehouse> warehouses = new ArrayList<>();
            int goalR = -1, goalC = -1;
            for (int j = 0; j < R; j++) {
                String str = in.nextLine();
//                System.out.println(str);
                for (int k = 0; k < C; k++) {
                    mat[j][k] = str.charAt(k);
                    if(mat[j][k] == 'W') {
                        warehouses.add(new Warehouse(j, k));
                    }
                    if(mat[j][k] == 'R') {
                        goalR = j;
                        goalC = k;
                    }
                }
            }

            Set<String> visited = new HashSet<>();
            Queue<int[]> frontier = new LinkedList<>();
            frontier.add(new int[]{goalR, goalC});
            while(!frontier.isEmpty()) {
                int[] next = frontier.poll();
                int r = next[0], c = next[1];
                if(mat[r][c] == 'W') {
                    System.out.println(r + " " + c);
                    continue outer;
                }
                if(mat[r][c] == '#') {
                    continue;
                }
                String hash = r + " " + c;
//                System.out.println(hash);
                if(visited.add(hash)) {
                    for (int j = 0; j < 4; j++) {
                        if (inBounds(r + dr[j], c + dc[j])) {
                            frontier.add(new int[]{r + dr[j], c + dc[j]});
                        }
                    }
                }
            }
            System.out.println("Send a helicopter");
//            System.out.println("WHAT");
        }
    }

    public static boolean inBounds(int r, int c) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }

    static class Warehouse {
        int r;
        int c;
        public Warehouse(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

}
