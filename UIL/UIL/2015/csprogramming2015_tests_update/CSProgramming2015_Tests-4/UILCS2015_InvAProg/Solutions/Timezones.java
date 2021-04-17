import java.io.*;
import java.util.*;

public class Timezones {

  static class Time {
    int sign;
    int hour;
    int minute;

    Time(int sign, int hour, int minute) {
      this.sign = sign;
      this.hour = hour;
      this.minute = minute;
    }

    Time offsetBy(Time o) {
      if (o.sign > 0) {
        int hour = (this.hour + o.hour + (this.minute + o.minute) / 60) % 24;
        int minute = (this.minute + o.minute) % 60;
        return new Time(1, hour, minute);
      } else {
        int hour = this.hour - o.hour;
        int minute = this.minute - o.minute;
        if (this.minute < o.minute) {
          --hour;
        }
        return new Time(1, (hour + 24) % 24, (minute + 60) % 60);
      }
    }

    public String toString() {
      return String.format("%02d:%02d",
                           this.hour,
                           this.minute);
    }
  }

  static class Zone {
    int hour;
    int minute;

    Zone(int sign, int hour, int minute) {
      if (sign > 0) {
        this.hour = hour + 12;
        this.minute = minute;
      } else {
        this.hour = 11 - hour;
        this.minute = 60 - minute;
        if (minute == 60) {
          ++hour;
          minute = 0;
        }
      }
    }

    Time difference(Zone o) {
      if (this.hour > o.hour
          || (this.hour == o.hour && this.minute >= o.minute)) {
        int hour = this.hour - o.hour;
        int minute = this.minute - o.minute;
        if (minute < 0) {
          minute += 60;
          --hour;
        }
        return new Time(1, hour, minute);
      } else {
        Time reverse = o.difference(this);
        reverse.sign = -reverse.sign;
        return reverse;
      }
    }

    public String toString() {
      return String.format("%02d:%02d",
                           this.hour,
                           this.minute);
    }
  }

  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(new File("timezones.dat"));
    int numZones = in.nextInt();
    Map<String, Zone> zones = new HashMap<String, Zone>();
    int numTimes = in.nextInt();
    in.nextLine();

    for (int i = 0; i < numZones; ++i) {
      String[] data = in.nextLine().split(" ");
      String name = data[0];
      String time = data[1];
      int sign = time.charAt(0) == '+' ? 1 : -1;
      int hour = Integer.parseInt(time.substring(1, 3));
      int minute = Integer.parseInt(time.substring(4, 6));
      zones.put(name, new Zone(sign, hour, minute));
    }

    for (int i = 0; i < numTimes; ++i) {
      String[] data = in.nextLine().split(" ");
      String time = data[0];
      String from = data[1];
      String to = data[3];
      Time origin = new Time(1,
                             Integer.parseInt(time.substring(0, 2)),
                             Integer.parseInt(time.substring(3, 5)));
      Time offset = zones.get(to).difference(zones.get(from));
      System.out.printf("%s %s\n", origin.offsetBy(offset), to);
    }
  }
}
