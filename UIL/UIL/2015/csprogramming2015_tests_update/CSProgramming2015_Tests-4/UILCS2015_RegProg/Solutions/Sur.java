//Solution for Sur
import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Sur {
	public static void main (String [] args) throws IOException
	{
		Scanner ff = new Scanner(new File("sur.dat"));
		int n = 10;
		int m=0,f=0,u=0;
		while(ff.hasNext()){
				String s = ff.nextLine();
				if (s.substring(s.length()-2).equals("ov"))
					m++;
				else
				if (s.substring(s.length()-3).equals("ova"))
					f++;
				else
					u++;
		}
		ff.close();
		out.println(m+" "+f+" "+u);
	}
}
/*
Example Input File
Andropov
Sharapova
Kournikova
Bobrov
Pakhomova
Yefimov
Gachev
Voskoboynikov
Nikitin
Severova

Example Output to Screen
4 4 2
Explanation of Output
There are 4 names that end in “ov”, 4 ending in “ova”, and 2 that are neither.

Judge’s Input File
Andropov
Sharapova
Kournikova
Bobrov
Pakhomova
Yefimov
Gachev
Voskoboynikov
Nikitin
Severova
Gorshkov
Taushev
Misalova
Gerasimov
Chendev
Chaykovsky
Shirmanova
Snatkin
Dubinin
Turfanova
Knyazev
Smagin
Loskutnikov
Chuzhinova
Kolesnikov
Khokhlachev
Mihaylovna
Mosalev
Alliluyev
Ivakin
Davydkin
Duranichev
Batishchev
Strekalova
Shulgin
Kulagin
Sevostyanova
Sergeyev
Tseydlits
Kedrov
Smeshnoy
Eybozhenko
Chayka
Krivkov
Baranovsky
Shulichenko
Desyatkov
Balakin
Shelagin
Pevchikh

Judge’s Output to Screen
11 10 29

*/