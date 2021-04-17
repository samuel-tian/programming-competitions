import static java.lang.System.out;

import java.util.Scanner;
import java.io.File;
import java.io.IOException;

import java.util.ArrayList;

public class main {

    public static class pair<F extends Comparable<F>, S extends Comparable<S> > implements Comparable<pair<F, S> > {
        public F f;
        public S s;
        public pair() {
            
        }
        public pair(F first, S second) {
            this.f = first;
            this.s = second;
        }
        public int compareTo(pair<F, S> other) {
            if (this.f.compareTo(other.f)==0) {
                return this.s.compareTo(other.s);
            }
            return this.f.compareTo(other.f);
        }
        public String toString() {
            return "(" + this.f + "," + this.s + ")";
        }
    }

    public static int dfs(ArrayList<Integer>[] adj, boolean[] vis, int a) {
        int ret = 1;
        for (int i : adj[a]) {
            if (vis[i])
                continue;
            vis[i] = true;
            ret += dfs(adj, vis, i);
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(new File("in.dat"));
        int t = scan.nextInt();
        while (t-- > 0) {
            int v = scan.nextInt();
            int e = scan.nextInt();
            ArrayList<Integer>[] adj = new ArrayList[v];
            for (int i = 0; i < v; i++) {
                adj[i] = new ArrayList<Integer>();
            }
            for (int i = 0; i < e; i++) {
                int a = scan.nextInt() - 1;
                int b = scan.nextInt() - 1;
                adj[a].add(b);
                adj[b].add(a);
            }
            boolean[] vis = new boolean[v];
            for (int i = 0; i < v; i++)
                vis[i] = false;
            int num_colors = 1;
            int num_ways = 1;
            for (int i = 0; i < v; i++) {
                if (!vis[i]) {
                    int num = dfs(adj, vis, i);
                    if (num>1) {
                        num_colors = 2;
                    }
                    num_ways *= 2;
                }
            }
            if (num_colors==1)
                out.printf("%d %d%n", num_colors, 1);
            else
                out.printf("%d %d%n", num_colors, num_ways);
        }
    }

}
