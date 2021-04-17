
import java.io.File;
import java.io.FileNotFoundException;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;
/**
 * 
 * @author sno
 * 
 * There are n people in the office. At the beginning of the workday they all know a single piece 
 * of information. There is a water cooler, if two or more people are at the water
 * cooler at any given moment, then they share all the information they have learned. 
 * 
 * At the end of the day, determine who has heard what stories.
 *
 */
public class Guadalupe {

	public static void main(String [] args) throws FileNotFoundException, UnsupportedEncodingException {
		Scanner f = new Scanner(new File("guadalupe.dat"));
		int N = f.nextInt(); f.nextLine();
		while(N-- >0) {
			int Q = f.nextInt(); f.nextLine();
			WaterCoolerPerson[] peeps = new WaterCoolerPerson[Q];
			int i = 0; 
			while(Q-- >0) {	
				String personTimes = f.nextLine();
				//System.out.println(personTimes);
				Scanner elements = new Scanner(personTimes);
				WaterCoolerPerson p = new WaterCoolerPerson(elements.next());
				while(elements.hasNext()) {
					p.times.add(new WaterCoolerTime(elements.next(), elements.next()));
				}
				peeps[i] = p;
				++i;				
			}
			atWaterCoolerAtSameTime(peeps);
			for(WaterCoolerPerson p: peeps) {
				System.out.print(p.name + " has heard gossip from: ");
				for(String name: p.personsStoriesHeard) {
					System.out.print(name + " ");
				}
				System.out.println();
			}
			System.out.println();
		}
	}
	
	/*
	 * Looks through each of the 1440 discrete moments of the day and see who is all at the
	 * water cooler during those times. All people there exchange stories.
	 */
	public static void atWaterCoolerAtSameTime(WaterCoolerPerson[] peeps) {	
		for(int i = 0 ; i < 23*60+59; i ++) {
			ArrayList<WaterCoolerPerson> atWaterCoolerAtThisTime = new ArrayList<WaterCoolerPerson> ();
			for(int j = 0; j < peeps.length; j++) {
				for(int k = 0; k < peeps[j].times.size(); k++) {
					if(peeps[j].times.get(k).during(i)) {
						atWaterCoolerAtThisTime.add(peeps[j]);
					}
				}
			}
			for(WaterCoolerPerson w: atWaterCoolerAtThisTime) {
				for(WaterCoolerPerson v: atWaterCoolerAtThisTime) {
					if(w == v) {
						continue;
					}
					w.heard(v);
				}
			}
		}
	}
}

/*
 * Keeps up with the names, schedules, and stories they have heard.
 */
class WaterCoolerPerson {
	public String name;
	public ArrayList<WaterCoolerTime> times;
	public TreeSet<String> personsStoriesHeard;
	public WaterCoolerPerson(String name) {
		this.name = name;
		times = new ArrayList<WaterCoolerTime>();
		personsStoriesHeard = new TreeSet<String>();
		personsStoriesHeard.add(name);
	}
	public void heard(WaterCoolerPerson v) {
		for(String s: v.personsStoriesHeard) {
			this.personsStoriesHeard.add(s);
		}
	}
}
/*
 * Easy time class that represents time as integers of minutes in the day (where the day begins at midnight)
 * and has some easy expressions surrounding them.
 * 
 * // 0 -- 0:00
 * // 1439 -- 23:59
 */
class WaterCoolerTime {
	public int arrivalTime;
	public int departureTime;
	public WaterCoolerTime(String arrive, String leave) {
		int hourArrive = Integer.parseInt(arrive.substring(0,arrive.indexOf(':')));
		int minuteArrive = Integer.parseInt(arrive.substring(arrive.indexOf(':')+1));
		arrivalTime = hourArrive*60 + minuteArrive;
		
		int hourDepart = Integer.parseInt(leave.substring(0,leave.indexOf(':')));
		int minuteDepart = Integer.parseInt(leave.substring(leave.indexOf(':')+1));
		departureTime = hourDepart*60 + minuteDepart;
	}
	public boolean during(int time) {
		if(time < departureTime && time >= arrivalTime) {
			return true;
		}
		return false;
	}
	public boolean before(int time) {
		return time < arrivalTime;
	}
	
	public boolean after(int time) {
		return time >= departureTime;
	}
}
