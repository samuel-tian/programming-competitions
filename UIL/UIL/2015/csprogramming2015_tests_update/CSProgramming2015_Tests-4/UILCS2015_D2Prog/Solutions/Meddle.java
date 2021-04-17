import java.io.File;
import java.util.*;

public class Meddle {
    public static void main(String ... bob) throws Exception {
        new Meddle().run("meddle.dat");
    }

    public void run(String file) throws Exception {
        Scanner in = new Scanner(new File(file));
        int testCases = in.nextInt();
        for (int i = 0; i < testCases; i++) {
            String toCheck = in.next();
            Map<Character, Node> allCharacters = createGraph(toCheck);
            int numWords = in.nextInt();
            for (int j = 0; j < numWords; j++) {
                String word = in.next();
                System.out.printf("%s: ", word);
                if(!allCharacters.containsKey(word.charAt(0))) {
                    System.out.println("NO");
                } else {
                    String ans = exists(allCharacters, -1, word, 0) ? "YES" : "NO";
                    System.out.println(ans);
                }
            }
            System.out.println();
        }
    }

    private boolean exists(Map<Character, Node> allCharacters, int keyIndex, String word, int index) {
        if(word.length() == index) { // We've successfully searched the whole word and arrived at the end
            return true;
        }
        Node next = allCharacters.get(word.charAt(index));
        if(next == null) {
            return false;
        }
        Integer nextIndex = next.indexes.higher(keyIndex);
        if(nextIndex == null)
            return false;
        if(exists(allCharacters, nextIndex, word, index + 1))
            return true;
        else
            return false;
    }


    private Map<Character, Node> createGraph(String toCheck) {
        // Each character is a node with edges to every character after it
        Map<Character, Node> map = new HashMap<>();
        int length = toCheck.length();
        for (int i = 0; i < length; i++) {
            char curCh = toCheck.charAt(i);
            placeNode(map, curCh, i);
            for (int j = i + 1; j < length; j++) {
                char parseCh = toCheck.charAt(j);
                placeNode(map, parseCh, j);
            }
        }
        return map;
    }

    private void placeNode(Map<Character, Node> map, char ch, int index) {
        if(map.containsKey(ch)) {
            map.get(ch).addIndex(index);
        }
        else {
            map.put(ch, new Node(ch, index));
        }
    }

    class Node {
        private TreeSet<Integer> indexes;
        private char letter;

        public Node(char ch, int index) {
            indexes = new TreeSet<>();
            letter = ch;
            indexes.add(index);
        }

        public void addIndex(int ind) {
            indexes.add(ind);
        }

        public String toString() {
            return String.format("%c-> %s", letter, indexes);
        }
    }
}
