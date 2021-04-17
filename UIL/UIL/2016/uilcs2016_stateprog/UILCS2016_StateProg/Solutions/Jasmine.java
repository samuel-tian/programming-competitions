/**
Jasmine loves to mess around with her friends' names by changing around the letters to make
crazy sounding new names. One thing she tried recently, even writing a program for it, was to divide
each name into three parts, then finding the longest part and putting that first in all caps, 
followed by the other two parts, the first lowercased and reversed, and the other part uppercased and
alphabetized.

She decided to divide each full name length by 3, and use that value as the length of the first two parts, 
which means the last part could possibly be longer than first two, but that was OK with her.

For example, since "Abigail" has 7 letters, the first two parts - "Ab" and "ig" - will be 2 characters long, 
and "ail" will be the third part. Since "ail" is the longest
part, which she puts it first in all caps, followed by "ba", the reversed and lowercased next part, and finally
"GI", the alphabetized and uppercased final part, making a new crazy name of "AILbaGI".

For Carlos, all three parts are the same length, so she just keeps them in order, capitalizing the first part, 
doing the "reverse/lowercase" thing with the second part, and the "alphaOrder/uppercase" thing with the
last part, producing "CAlrOS" as his new crazy name.

Input - Several names of friends' names, each on one line, as shown below.

Output - For each name, output the "splits", followed by " ==> ", and then the new crazy name according to the
criteria specified above.

Sample data:
Abigail
Benjamin
Carlos
Dara
Emiliano
Fujita
Guadalupe
Heng
Ignacio
jasmine
Kamalika
Luna
Rumpelstiltskin
Rosannarosanadana

Sample Output:
Ab ig ail ==> AILbaGI
Be nj amin ==> AMINebJN
Ca rl os ==> CAlrOS
D a ra ==> RAdA
Em il iano ==> IANOmeIL
Fu ji ta ==> FUijAT
Gua dal upe ==> GUAladEPU
H e ng ==> NGhE
Ig na cio ==> CIOgiAN
ja sm ine ==> INEajMS
Ka ma lika ==> LIKAakAM
L u na ==> NAlU
Rumpe lstil tskin ==> RUMPElitslIKNST
Rosan naros anadana ==> ANADANAnasorANORS

 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import static java.lang.System.*;
public class Jasmine {
	public static void main(String [] args) throws FileNotFoundException {
		Scanner f = new Scanner(new File("jasmine.dat"));
		while(f.hasNext()) {
			
			args=new String[3];
			String s = f.next();
			int div = s.length()/3;
			int lng=0;
			args[0] = s.substring(0,div);
			args[1] = s.substring(div,div*2);
			if(args[1].length()>args[lng].length())lng=1;
			args[2] = s.substring(div*2);
			if(args[2].length()>args[lng].length())lng=2;
			out.print(args[0]+" "+args[1]+" "+args[2]+" ==> ");
			out.print(args[lng].toUpperCase());
			if(lng==0){
				StringBuilder sb = new StringBuilder(args[1].toLowerCase()).reverse();
				out.print(sb);
				char[]lets=args[2].toCharArray();
				Arrays.sort(lets);
				out.println(new String(lets).toUpperCase());
			}
			else
			if(lng==2){
				StringBuilder sb = new StringBuilder(args[0].toLowerCase()).reverse();
				out.print(sb);
				char[]lets=args[1].toCharArray();
				Arrays.sort(lets);
				out.println(new String(lets).toUpperCase());
			}
						
		}
	}
}
/*
Test Data:
Ab ig ail ==> AILbaGI
Be nj amin ==> AMINebJN
Ca rl os ==> CAlrOS
D a ra ==> RAdA
Em il iano ==> IANOmeIL
Fu ji ta ==> FUijAT
Gua dal upe ==> GUAladEPU
H e ng ==> NGhE
Ig na cio ==> CIOgiAN
ja sm ine ==> INEajMS
Ka ma lika ==> LIKAakAM
L u na ==> NAlU
Rumpe lstil tskin ==> RUMPElitslIKNST
Rosan naros anadana ==> ANADANAnasorANORS

Test Output:
Ab ig ail ==> AILbaGI
Be nj amin ==> AMINebJN
Ca rl os ==> CAlrOS
D a ra ==> RAdA
Em il iano ==> IANOmeIL
Fu ji ta ==> FUijAT
Gua dal upe ==> GUAladEPU
H e ng ==> NGhE
Ig na cio ==> CIOgiAN
ja sm ine ==> INEajMS
Ka ma lika ==> LIKAakAM
L u na ==> NAlU
Rumpe lstil tskin ==> RUMPElitslIKNST
Rosan naros anadana ==> ANADANAnasorANORS

*/