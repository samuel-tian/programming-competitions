
import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Fuel {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new File("fuel.dat"));
        int numSets = s.nextInt();
        s.nextLine();

        for(int i = 1; i <= numSets; i++){
            System.out.println("Data Set " + i);
            int days = s.nextInt();
            s.nextLine();
            int leaves = 0;
            int rfs = 0;
            int pdf = 0;
            String[] data = s.nextLine().trim().split("\\s+");
            for(int j = 0; j < days; j++){
                int plants = 0;
                int height = 0;
                if( j * 2 < data.length ){
                    plants = Integer.parseInt(data[j * 2]);
                    height = Integer.parseInt(data[j * 2 + 1]);
                }
                pdf += rfs / 17;
                rfs = rfs % 17 + leaves / 177;
                leaves = leaves % 177 + plants * height * 25;
                // System.out.println(leaves + " " + rfs + " " + pdf);
                System.out.print("Day " + (j + 1) + " " + pdf);
                if(j != (days - 1))
                    System.out.print(", ");
            }
            System.out.println();
        }
        s.close();
    }
}

