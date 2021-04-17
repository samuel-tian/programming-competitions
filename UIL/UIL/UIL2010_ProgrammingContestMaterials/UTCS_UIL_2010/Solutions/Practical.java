package _UTCS_2010;

import java.io.*;
import java.util.*;

public class Practical {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("practical.dat"));
        int numSets = s.nextInt();

        for(int i = 1; i <= numSets; i++){
            int num = s.nextInt();
            ArrayList<Integer> factors = findFactors(num);
            boolean practical = checkPractical(factors, num);
            if(practical)
                System.out.println("PRACTICAL");
            else
                System.out.println("NOT PRACTICAL");
        }
        s.close();
    }



    private static boolean checkPractical(ArrayList<Integer> factors, int num) {
        if(num == 1 || num == 2)
            return true;
        else if( num % 2 == 1)
            return false;
        else{
            boolean good = true;
            int x = 4;
            while(good && x < num){
                good = canSum(factors, x, 0);
                x++;
            }
            return good;
        }
    }



    private static boolean canSum(ArrayList<Integer> factors, int target, int sum) {
        if(sum == target)
            return true;
        else if(sum > target)
            return false;
        else if(factors.size() == 0)
            return false;
        else {
            int temp = factors.remove(factors.size() - 1);
            // try sum without current factor
            boolean canSolve = canSum(factors, target, sum + temp);
            if(!canSolve){
                // try sum with current factor
                canSolve = canSum(factors, target, sum);
            }
            // put it back for later
            factors.add(temp);
            return canSolve;
        }
    }



    private static ArrayList<Integer> findFactors(int num) {
        TreeSet<Integer> set = new TreeSet<Integer>();
        set.add(1);
        double limit = Math.sqrt(num);
        for(int i = 2; i <= limit; i++){
            if(num % i == 0){
                set.add(i);
                set.add(num / i);
            }
        }
        ArrayList<Integer> result = new ArrayList<Integer>(set);
        // System.out.println(result);
        return result;
    }
}
