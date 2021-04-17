import static java.lang.System.out;

import java.util.Scanner;
import java.io.File;
import java.io.IOException;

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

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(new File("in.dat"));

    }

}
