import java.util.*;
import java.io.*;

public class Pratik {
  public static void main(String [] args) throws FileNotFoundException {
    //String input = "5:13 pm"; //-> 6:30 pm -> 18:30 (time in Kolkata from Texas)
    Scanner f = new Scanner(new File("pratik.dat"));
    int N = f.nextInt(); f.nextLine();
    while(N-- > 0) {
      String input = f.nextLine();
      String callPerson = f.nextLine();
      String[] timeSplit = input.split(":");
      int hour = Integer.parseInt(timeSplit[0]);
      String[] minuteSplit = timeSplit[1].split(" ");
      int minute = Integer.parseInt(minuteSplit[0]);


      if(hour == 12 && minuteSplit[1].equals("am")) {
        hour -= 12;
      }

      if(minuteSplit[1].equals("pm")) {
        if(hour < 12) {
            hour += 12;
        }
      }

      // Mom is in the same time zone, but the others are all over
      switch(callPerson) {
        case "Aunt Tapasi": {
          // kolkata
          hour += 11;
          minute += 30;
        } break;
        case "Grandpa Aadi": {
          // nepal
          hour += 11;
          minute += 45;
        } break;
        case "Cousin Gulasyl": {
          // Aktobe
          hour += 11;
        } break;
        case "Uncle Ardem":
        case "Second Cousin Bongi": {
          // South Africa
          hour += 8;
        } break;
      }


      if(minute >= 60) {
        minute -= 60;
        hour += 1;
      }

      if(hour >=24) {
        hour -= 24;
      }


      String indiaTime = (hour < 10 ? "0": "") + hour + ":" + (minute < 10 ? "0": "") + minute;
      String[] output = {"","","","",""};


      for(int i = 0; i < indiaTime.length(); i++) {
        char c = indiaTime.charAt(i);
        int index = -1;
        if(c == ':') {
          index = 10;
        } else {
          index = Integer.parseInt(c+"");
        }
        for(int j = 0; j < TimeRender.nums[index].length; j++) {
          output[j] += TimeRender.nums[index][j] + " ";
        }
      }

      for(int i = 0; i < output.length; i++) {
        System.out.println(output[i]);
      }
      System.out.println();
    }
  }
}

class TimeRender {
  final static String [][] nums = {{
    "#####",
    "#   #",
    "#   #",
    "#   #",
    "#####"
  },{
    "    #",
    "    #",
    "    #",
    "    #",
    "    #"
  },{
    "#####",
    "    #",
    "#####",
    "#    ",
    "#####"
  },{
    "#####",
    "    #",
    "#####",
    "    #",
    "#####"
  },{
    "#   #",
    "#   #",
    "#####",
    "    #",
    "    #"
  },{
    "#####",
    "#    ",
    "#####",
    "    #",
    "#####"
  },{
    "#####",
    "#    ",
    "#####",
    "#   #",
    "#####"
  },{
    "#####",
    "    #",
    "    #",
    "    #",
    "    #"
  },{
    "#####",
    "#   #",
    "#####",
    "#   #",
    "#####"
  },{
    "#####",
    "#   #",
    "#####",
    "    #",
    "#####"
  },{
    " ",
    ".",
    " ",
    ".",
    " "
  }};
}
