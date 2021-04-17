
import java.awt.Rectangle;
import java.io.*;
import java.util.*;

public class Shared {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("shared.dat"));
        int numSets = s.nextInt();
        s.nextLine();
        for(int i = 1; i <= numSets; i++){
            Rectangle[] rects = new Rectangle[2];
            for(int k = 0; k < 2; k++){
                int[] coords = new int[4];
                for(int j = 0; j < 4; j++)
                    coords[j] = s.nextInt();
                s.nextLine();
                int width = Math.abs(coords[0]- coords[2]);
                int height = Math.abs(coords[1] - coords[3]);
                boolean firstLeft = coords[0] < coords[2];
                boolean firstUpper = coords[1] > coords[3];
                int x = coords[0];
                int y = coords[1];
                if(!firstLeft)
                    x -= width;
                if(!firstUpper)
                    y += height;
                rects[k] = new Rectangle(x, y, width, height);
                // System.out.println(rects[k]);
            }
            Rectangle result = getIntersection(rects[0], rects[1]);
            // System.out.println("intersection: " + result);
            int area = result.height * result.width;
            if(result.height <= 0 || result.width <= 0)
                System.out.println(0);
            else
                System.out.println(result.height * result.width);
        }
        s.close();
    }

    public static Rectangle getIntersection(Rectangle r1, Rectangle r2){
        int r1x2 = r1.x + r1.width;
        int r1y2 = r1.y - r1.height;
        int r2x2 = r2.x + r2.width;
        int r2y2 = r2.y - r2.height;
        int resultX1 = r1.x;
        if (r2.x > resultX1 ) resultX1 = r2.x;
        int resultY1 = r1.y;
        if (r2.y < resultY1) resultY1 = r2.y;
        int resultX2 = r1x2;
        if (r2x2 < resultX2) resultX2 = r2x2;
        int resultY2 = r1y2;
        if (r2y2 > resultY2) resultY2 = r2y2;
        int resultWidth = resultX2 - resultX1;
        int resultHeight = resultY1 - resultY2;

        Rectangle result = new Rectangle(resultX1, resultY1, resultWidth, resultHeight);
        // System.out.println(result);
        return result;
    }
}