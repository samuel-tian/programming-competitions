import java.io.File;
import java.util.Arrays;
import java.util.Scanner;

public class Speedy {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("speedy.dat"));
        int cases = in.nextInt();
        for (int i = 0; i < cases; i++) {
            int N = in.nextInt(), T = in.nextInt();
            Person[] people = new Person[N];
            for (int j = 0; j < N; j++) {
                people[j] = new Person(in.nextInt(), in.nextInt());
            }
            Arrays.sort(people);

            int count = 0;
            for (int j = 0; j < N; j++) {
                Person start = people[j];
                for (int k = j + 1; k < N; k++) {
                    Person compare = people[k];
                    if(start.startTime <= compare.startTime) {
                        if(start.speed < compare.speed) {
                            int startEndLoc = (T - start.startTime) * start.speed;
                            int compareEndLoc = (T - compare.startTime) * compare.speed;
                            if(compareEndLoc > startEndLoc) {
                                count++;
                            }
                        }
                    }
                }
            }

            System.out.println(count);
//            System.out.println(bruteForce(people, T));
        }
    }

    public static int bruteForce(Person[] people, int T) {
        int count = 0;
        for (int i = 0; i < T; i++) {
            boolean[][] lessThan = new boolean[people.length][people.length];
            for (int j = 0; j < people.length; j++) {
                for (int k = 0; k < people.length; k++) {
                    if(people[j].loc <= people[k].loc) {
                        lessThan[j][k] = true;
                        lessThan[k][j] = false;
                    }
                }
            }
            for (int j = 0; j < people.length; j++) {
                int startTime = people[j].startTime;
                int speed = people[j].speed;
                if(startTime <= i) {
                    people[j].loc += speed;
                }
            }
            for (int j = 0; j < people.length; j++) {
                for (int k = 0; k < people.length; k++) {
                    if(j != k) {
                        if(lessThan[j][k] && people[j].loc > people[k].loc) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }

    static class Person implements Comparable<Person> {
        int speed;
        int loc;
        int startTime;
        public Person(int ST, int sp) {
            startTime = ST;
            speed = sp;
            loc = 0;
        }

        public int compareTo(Person other) {
            if(startTime == other.startTime) {
                return speed - other.speed;
            }
            return startTime - other.startTime;
        }

        public String toString() {
            return startTime + " " + speed;
        }


    }
}
