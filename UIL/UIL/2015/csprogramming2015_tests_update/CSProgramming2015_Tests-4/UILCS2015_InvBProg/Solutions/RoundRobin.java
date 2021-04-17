import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class RoundRobin {

    public static void main(String[] args) throws IOException {
        final Scanner scanner = new Scanner(new File("roundrobin.dat"));
        int T = scanner.nextInt();
        while (T-- > 0) {
            runTestCase(scanner);
            if (T > 0) {
                System.out.println();
            }
        }
    }

    private static void runTestCase(Scanner scanner) {
        final int N = scanner.nextInt();
        final int M = scanner.nextInt();
        scanner.nextLine();

        final String[] names = new String[N];
        for (int i = 0; i < N; i++) {
            names[i] = scanner.nextLine();
        }

        boolean[][] gameMatrix = new boolean[N][N]; // defaults to all false
        final Set<String> missing = new TreeSet<>();
        final Set<String> duplicates = new TreeSet<>();

        boolean works = true;
        for (int i = 0; i < M; i++) {
            final String gameString = scanner.nextLine();
            final String[] teamNumbers = gameString.split(" v ");
            int teamA = Integer.parseInt(teamNumbers[0]) - 1;
            int teamB = Integer.parseInt(teamNumbers[1]) - 1;
            if (!works) {
                continue;
            }

            if (teamA == teamB || teamA < 0 || teamB < 0 || teamA >= N || teamB >= N) {
                works = false;
            }

            if (gameMatrix[teamA][teamB] || gameMatrix[teamB][teamA]) {
                duplicates.add(stringMin(names[teamA] + " v " + names[teamB], names[teamB] + " v " + names[teamA]));
            }

            gameMatrix[teamA][teamB] = true;
            gameMatrix[teamB][teamA] = true;
        }

        if (!works) {
            System.out.println("NO");
            System.out.println("INVALID GAMES");
            return;
        }

        //Check for missing games
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j && !gameMatrix[i][j]) {
                    missing.add(stringMin(names[i] + " v " + names[j], names[j] + " v " + names[i]));
                }
            }
        }

        // Print out answer
        if (missing.size() == 0 && duplicates.size() == 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
            if (missing.size() > 0) {
                System.out.println("MISSING GAMES");
                for (String game : missing) {
                    System.out.println(game);
                }
            }

            if (duplicates.size() > 0) {
                System.out.println("DUPLICATE GAMES");
                for (String game : duplicates) {
                    System.out.println(game);
                }
            }
        }
    }

    private static String stringMin(String a, String b) {
        if (a.compareTo(b) < 0) {
            return a;
        } else {
            return b;
        }
    }
}
