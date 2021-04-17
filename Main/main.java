import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Scanner;
import java.io.File;

import java.util.TreeMap;
import java.util.ArrayList;
import java.util.Collections;

public class main {

    public static long fastpow(long base, long exp, long mod) {
        if (exp == 0)
            return 1;
        if (exp == 1)
            return base % mod;
        long ans = fastpow(base, exp / 2, mod);
        if (exp % 2 == 0) {
            return (ans*ans)%mod;
        }
        else
            return (ans*ans*base)%mod;
    }

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(new File("reka.dat"));
        int t = scan.nextInt();
        for (int q = 1; q <= t; q++) {
            System.out.print("Case #" + q + ": ");
            long l = scan.nextLong();
            int c = scan.nextInt();
            TreeMap<Long, String> tm = new TreeMap<>();
            ArrayList<Long> arrKey = new ArrayList<>();
            ArrayList<String> arrValue = new ArrayList<>();
            for (int i = 0; i < c; i++) {
                long ind = scan.nextLong() - 1;
                String ch = scan.next();
                arrKey.add(ind);
                arrValue.add(ch);
                tm.put(ind, ch);
            }
            // Collections.sort(arr);
            boolean bad = false;
            for (int i = 0; i < arrKey.size(); i++) {
                long key = arrKey.get(i);
                String val = arrValue.get(i);
                if (tm.containsKey(l - key-1)) {
                    if (!tm.get(key).equals(tm.get(l-key-1))) {
                        bad = true;
                        break;
                    }
                }
            }
            if (bad) {
                System.out.println(0);
                continue;
            }
            int tot = (l+1)/2;
            
            for (long i = 0; i < (l+1)/2; i++) {
                if (tm.containsKey(i) || tm.containsKey(l-i-1))
                    continue;
                tot++;
            }
            long mod = 1000000000;
            long ans = fastpow(26, tot, mod);
            System.out.println(ans);
        }
    }
}

