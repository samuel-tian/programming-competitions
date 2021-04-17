import java.util.*;
import java.io.*;

public class Honza {
  public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("honza.dat"));
		int N = f.nextInt();f.nextLine();
		while(N-->0)
		{
			String date = f.next();
			int month = Integer.parseInt(date.substring(0,date.indexOf("/")));
			date = date.substring(date.indexOf("/")+1);
			int day = Integer.parseInt(date.substring(0,date.indexOf("/")));
			date = date.substring(date.indexOf("/")+1);
			int year = Integer.parseInt(date);

      String time = f.next();
      String[] timePieces = time.split(":");
      int hour = Integer.parseInt(timePieces[0]);
      int minute = Integer.parseInt(timePieces[1]);

			Calendar cal = Calendar.getInstance();
			cal.set(year, month-1, day, hour, minute);

			long numMinutes = f.nextLong() - 5;
      int tooBigFactor = (int) (numMinutes / (long)Integer.MAX_VALUE);
      int tooBigLeftovers = (int) (numMinutes % (long)Integer.MAX_VALUE);
      for(int i = 0; i < tooBigFactor; i++) {
          cal.add(Calendar.MINUTE, Integer.MAX_VALUE);
      }
      cal.add(Calendar.MINUTE, tooBigLeftovers);


			String day_of_week = (cal.getTime()+"").substring(0,3)+"";
			String calc_day = cal.get(Calendar.DAY_OF_MONTH)+"";
			String calc_year =cal.get(Calendar.YEAR)+"";
			String calc_month = cal.get(Calendar.MONTH)+1+"";
			System.out.println(day_of_week + " " + calc_month + "/" + calc_day + "/" + calc_year +
        " " + String.format("%02d:%02d",cal.get(Calendar.HOUR_OF_DAY), cal.get(Calendar.MINUTE)));
		}
	}
}
