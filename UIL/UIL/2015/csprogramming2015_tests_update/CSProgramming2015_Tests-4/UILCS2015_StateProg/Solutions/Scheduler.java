import java.io.*;
import java.util.*;

public class Scheduler {

  static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  static int lcm(int a, int b) {
    return a * b / gcd(a, b);
  }

  static class Task implements Comparable<Task>{
    static int nextId = 0;
    int id;

    int time, executed;
    int p, d, e;
    Task(int p, int d, int e) {
      this.id = nextId++;
      this.time = this.executed = 0;
      this.p = p;
      this.d = d;
      this.e = e;
    }

    void step(int t) {
      time += t;
    }

    void execute(int t) {
      executed += t;
    }

    boolean isCompleted() {
      return executed >= e * ((time / p) + 1);
    }

    boolean isOverdue() {
      return !isCompleted() && time >= ((time / p) * p + d);
    }

    @Override
    public int compareTo(Task o) {
      if (isCompleted() && !o.isCompleted())
        return 1;
      else if (!isCompleted() && o.isCompleted())
        return -1;
      else if (!isCompleted() && !o.isCompleted())
        return (d - (time % p)) - (o.d - (o.time % o.p));
      else
        return 0;
    }

    @Override
    public String toString() {
      return String.format("%d: %d %d %d", id, p, d, e);
    }
  }

  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(new File("scheduler.dat"));
    int numTests = in.nextInt();
    for (int test = 0; test < numTests; ++test) {
      int numTasks = in.nextInt();
      ArrayList<Task> tasks = new ArrayList<Task>();
      for (int task = 0; task < numTasks; ++task) {
        tasks.add(new Task(in.nextInt(), in.nextInt(), in.nextInt()));
      }
      int lcm = 1;
      for (Task t : tasks)
        lcm = lcm(lcm, t.p);

      // Implements earliest deadline first algorithm
      boolean success = true;
outer:
      for (int i = 0; i < lcm; ++i) {
        // System.out.printf("Time %02d:\n", i);
        Collections.sort(tasks);
        if (!tasks.get(0).isCompleted()) {
          // System.out.printf("\tExecuting: %s\n", tasks.get(0));
          tasks.get(0).execute(1);
        } else {
          // System.out.printf("\tIdle\n");
        }
        for (Task t : tasks)
          t.step(1);
        for (Task t : tasks) {
          if (t.isOverdue()) {
            // System.out.printf("\tOverdue: %s\n", t);
            success = false;
            break outer;
          }
        }
      }

      System.out.println(success ? "SCHEDULABLE" : "NOT SCHEDULABLE");
    }
  }
}
