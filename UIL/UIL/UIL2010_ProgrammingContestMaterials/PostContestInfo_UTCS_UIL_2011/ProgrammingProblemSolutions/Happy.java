import java.io.*;
import java.util.*;

public class Happy {
    public static void main(String[] args) {
        int i = 1;
        int[] indices = {10, 100, 500, 1000, 2000};
        int index = 0;
        int numHappy = 0;
        while(index < indices.length) {
            int n = i;
            ArrayList<Integer> nums = new ArrayList<Integer>();
            while(n != 1 && !nums.contains(n)) {
                nums.add(n);
                final int NUM_DIGITS = ("" + n).length();
                int[] digits = new int[NUM_DIGITS];
                for(int j = 0; j < NUM_DIGITS; j++) {
                    digits[j] = n % 10;
                    n /= 10;
                }
                n = 0;
                for(int j = 0; j < NUM_DIGITS; j++)
                    n += digits[j] * digits[j];
            }

            if(n == 1){
                numHappy++;
                if(numHappy == indices[index]) {
                    System.out.println(i);
                    index++;
                }
            }
            // System.out.print(nums);
            i++;
        }

    }
}
