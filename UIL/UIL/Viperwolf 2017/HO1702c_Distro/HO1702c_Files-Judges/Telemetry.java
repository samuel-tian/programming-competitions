import java.util.Scanner;
import java.io.File;
import java.util.Random;


public class Telemetry
{
	private static String sync = Integer.toBinaryString(0xFE6B2840);
	private static int keyLen = 3 * Byte.SIZE;
	private static int valLen = Integer.SIZE;

	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(new File("telemetry.dat"));
				
		String raw = fin.nextLine();
		String data = "";
		
		char prev = '0';
		for (int i = 1; i < raw.length(); i++) {
			if (raw.charAt(i) == prev) { data += 0;}
			else { data += 1; }
			prev = raw.charAt(i);
		}
				
		int keyPos = data.indexOf(sync) + sync.length();
		int valPos = keyPos + keyLen;
		
		String key = data.substring(keyPos, keyPos + keyLen);
		String value = data.substring(valPos, valPos + valLen);
		
		for (int i = 0; i < key.length(); i += 8) {
			String bits = key.substring(i, i + 8);
			System.out.print((char)Integer.parseInt(bits, 2));
		}
		System.out.println("=" + Integer.parseInt(value, 2));
		
		fin.close();
	}
	
/*	// Sample Data
	private static String KEY = "PTS";
	private static int VALUE = 60;
	private static Random RNG = new Random(0);
//*/

//*	// Judges Data
	private static String KEY = "RGB";
	private static int VALUE = 1234567890;
	private static Random RNG = new Random(1);
//*/	
/*	// Encode the origninal message into a telemetry stream (for generating input data)	
	static {
 		int LENGTH = 77 * 4;
		int padding = 5;
		
		String noise = "";
		for (int i = 0; i < LENGTH; i++) {
			noise += (RNG.nextInt(2) == 0 ? "0" : "1");
		}
		int noiseLen = noise.length() - sync.length() - (KEY.length() * 8 - Integer.SIZE);
		int noiseHead = RNG.nextInt(noiseLen - (padding * 2)) + padding;
		System.out.println("Location of sync pulse: " + noiseHead);
		
		String raw = "0" + noise.substring(0, noiseHead) + sync;
		for (int i = 0; i < KEY.length(); i++) {
			String bits = "00000000" + Integer.toBinaryString(KEY.charAt(i));
			raw += bits.substring(bits.length() - Byte.SIZE);
		}
		
		String bits = "00000000000000000000000000000000";
		bits += Integer.toBinaryString(VALUE);
		raw += bits.substring(bits.length() - Integer.SIZE);
		
		
		raw += noise.substring(raw.length());
		String nrzm = "";
		char prev = '0';
		for (int i = 0; i < raw.length(); i++) {
			if (raw.charAt(i) == '1') { prev = (prev == '1' ? '0' : '1'); }
			nrzm += prev;
		}
		
		System.out.println("Encoded: " + nrzm);
		System.exit(0);
	}
//*/
}