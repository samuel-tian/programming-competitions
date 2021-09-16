import static java.lang.System.out;

import java.util.Scanner;
import java.io.File;
import java.io.IOException;

import java.util.HashMap;

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
        HashMap<String,Integer> hm = new HashMap<>();
        hm.put("I", 1);
        hm.put("V", 5);
        hm.put("X", 10);
        hm.put("L", 50);
        hm.put("C", 100);
        hm.put("D", 500);
        hm.put("M", 1000);
        hm.put("IV", 4);
        hm.put("IX", 9);
        hm.put("XL", 40);
        hm.put("XC", 90);
        hm.put("CD", 400);
        hm.put("CM", 900);
        while (scan.hasNext()) {
            String in = scan.next(); 
            int ans = 0;
            int i = 0;
            while (i < in.length()) {
                if (i+1 < in.length()) {
                    if (hm.containsKey(in.substring(i,i+2))) {
                        ans += hm.get(in.substring(i,i+2));
                        i+=2;
                        continue;
                    }
                }
                ans += hm.get(in.substring(i,i+1));
                i+=1;
            }
            out.println(ans);
        }
    }

}
