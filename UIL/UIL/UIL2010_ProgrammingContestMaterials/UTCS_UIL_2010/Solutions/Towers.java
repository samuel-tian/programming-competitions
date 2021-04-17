
import java.io.*;
import java.util.*;

public class Towers {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("towers.dat"));
        int numSets = s.nextInt();
        s.nextLine();

        for(int i = 1; i <= numSets; i++){
            System.out.print("Data Set " + i + " Maximum Possible Height ");
            int towers = s.nextInt();
            int numBlocks = s.nextInt();
            ArrayList<Integer> blocks = new ArrayList<Integer>();
            int total = 0;
            for(int j = 0; j < numBlocks; j++){
                blocks.add(s.nextInt());
                total += blocks.get(blocks.size() - 1);
            }
            Collections.sort(blocks);
            int trueMax = total / towers;
            int[] heights = new int[towers];
            int max = findMax(blocks, heights, trueMax);
            System.out.println(max);
        }
        s.close();
    }

    private static int findMax(ArrayList<Integer> blocks, int[] heights,
            int trueMax) {

//        System.out.println(blocks);
//        System.out.println(Arrays.toString(heights));
        // check if any tower over
        for(int i = 0; i < heights.length; i++)
            if(heights[i] > trueMax)
                return 0;

        // if no blocks left check all equal
        if(blocks.size() == 0){
            if(allEqual(heights))
                return heights[0];
            else return 0;
        }

        // blocks left, try last one on all towers
        int currentBlock = blocks.remove(blocks.size() - 1);
        int maxFound = allEqual(heights) ? heights[0] : 0;
//        if(maxFound != 0)
//            System.out.println(maxFound);
        for(int i = 0; i < heights.length; i++){
            heights[i] += currentBlock;
            int tempMax = findMax(blocks, heights, trueMax);
            if(tempMax > maxFound)
                maxFound = tempMax;
            heights[i] -= currentBlock;
        }
        //try on no tower
        int tempMax = findMax(blocks, heights, trueMax);
        if(tempMax > maxFound)
            maxFound = tempMax;
        blocks.add(currentBlock);
        return maxFound;
    }

    public static boolean allEqual(int[] vals){
        for(int i = 1; i < vals.length; i++)
            if(vals[i] != vals[0])
                return false;
        return true;

    }
}