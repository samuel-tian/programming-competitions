import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Scanner;

public class main {

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        String next() throws IOException {
            while (st==null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine().trim());
            }
            return st.nextToken();
        }
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        double readDouble() throws IOException {
            return Double.parseDouble(next());
        }
        char readCharacter() throws IOException {
            return next().charAt(0);
        }
        String readLine() throws IOException {
            return br.readLine().trim();
        }
    }
    static FastScanner scan = new FastScanner();
    static PrintWriter out = new PrintWriter(System.out);

    public static class pair<F extends Comparable<F>, S extends Comparable<S> > implements Comparable<pair<F, S> > {
        public F f;
        public S s;
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

    public static void main(String[] args) throws IOException {
        out.flush();
        out.close();
    }

}
