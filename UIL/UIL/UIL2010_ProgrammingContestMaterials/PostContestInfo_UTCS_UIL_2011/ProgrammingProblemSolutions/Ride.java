import java.io.*;
import java.util.*;

public class Ride {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("ride.dat"));
        int numSets = s.nextInt();
        s.nextLine();

        for(int i = 1; i <= numSets; i++){
            int temp = s.nextInt();
            int time = s.nextInt();
            String rain = s.next();
            String group = s.next();
            assert -100 <= temp && temp <= 130;
            assert 0 <= time && time <= 23;
            assert rain.equals("RAIN") || rain.equals("NORAIN");
            assert group.equals("GROUP") || group.equals("ALONE");
            String result = "GYM";
            if(group.equals("ALONE") && (6 <= time && time <= 18) ) {
                if(rain.equals("NORAIN") && (30 <= temp && temp <= 110))
                    result = "RIDE";
                else if(rain.equals("RAIN") && (70 <= temp && temp <= 115))
                    result = "RIDE";
            }
            else if(group.equals("GROUP") && (7 <= time && time <= 21)) {
                if(rain.equals("NORAIN") && (20 <= temp && temp <= 105))
                    result = "RIDE";
                else if(rain.equals("RAIN") && (70 <= temp && temp <= 110))
                    result = "RIDE";
            }
            System.out.println("data set " + i + ": " + result);
        }
        s.close();
    }
}