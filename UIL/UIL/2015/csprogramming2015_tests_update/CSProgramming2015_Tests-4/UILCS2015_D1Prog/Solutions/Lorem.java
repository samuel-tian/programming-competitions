import java.io.*;
import java.util.*;

public class Lorem {

  static class Word implements Comparable<Word> {
    String word;
    float prob;

    Word(String word, float prob) {
      this.word = word;
      this.prob = prob;
    }

    public int compareTo(Word other) {
      return other.prob == prob ? word.compareTo(other.word) : (int) Math.signum(other.prob - prob);
    }

    @Override
    public String toString() {
      return String.format("%.2f,%s", prob, word);
    }
  }

  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(new File("lorem.dat"));
	int C = in.nextInt();
	in.nextLine();
	for(int a = 0; a < C; a++)
	{
	
	    TreeMap<String, TreeMap<String, Integer>> words =
	        new TreeMap<String, TreeMap<String, Integer>>();
	
	    int lines = in.nextInt();
	    in.nextLine();
	    for (int z = 0; z < lines; ++z) {
	      String[] line = in.nextLine().trim().split(" ");
	      for (int i = 1; i < line.length; ++i) {
	        if (!words.containsKey(line[i - 1]))
	          words.put(line[i - 1], new TreeMap<String, Integer>());
	        if (!words.get(line[i - 1]).containsKey(line[i]))
	          words.get(line[i - 1]).put(line[i], 0);
	        words.get(line[i - 1]).put(line[i], words.get(line[i - 1]).get(line[i]) + 1);
	      }
	    }
	
	    for (Map.Entry<String, TreeMap<String, Integer>> entry : words.entrySet()) {
	      if (entry.getValue().isEmpty())
	        continue;
	      ArrayList<Word> probs = new ArrayList<Word>();
	      float total = 0;
	      for (Map.Entry<String, Integer> word : entry.getValue().entrySet())
	        total += word.getValue();
	      for (Map.Entry<String, Integer> word : entry.getValue().entrySet())
	        probs.add(new Word(word.getKey(), word.getValue() / total));
	      Collections.sort(probs);
	
	      System.out.printf("%s:", entry.getKey());
	      for (Word w : probs)
	        System.out.printf(" %s", w.toString());
	      System.out.println();
	    }
	    System.out.println();
	}
  }
}
