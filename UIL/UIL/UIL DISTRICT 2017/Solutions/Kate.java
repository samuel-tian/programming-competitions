import java.util.*;
import java.io.*;


public class Kate {
  public static void main(String [] args) throws FileNotFoundException {
    Scanner f = new Scanner(new File("kate.dat"));
    int N = f.nextInt();f.nextLine();
    while(N-- > 0) {
      ArrayList<Double> coeffientsList = new ArrayList<>();
      ArrayList<Double> exponentsList = new ArrayList<>();
      boolean coeffientIsNegative = false;
      Scanner chop = new Scanner(f.nextLine());
      while(chop.hasNext()) {
        String term = chop.next();
        if(term.equals("-")) {
          coeffientIsNegative = true;
          continue;
        }
        if(term.equals("+")) {
          coeffientIsNegative = false;
          continue;
        }

        String[] parts = term.split("x");
        //coeffient
        double c = Double.parseDouble(parts[0]);
        if(coeffientIsNegative) {
          c *= -1;
        }
        coeffientsList.add(c);
        if(parts.length == 1) {

          if(term.indexOf('x') < 0) {
            //exponent = 0
            exponentsList.add(0.0);
          } else {
            //exponent = 1
            exponentsList.add(1.0);
          }
          continue;
        }
        exponentsList.add(Double.parseDouble(parts[1].substring(1)));
      }

    //  System.out.println(coeffientsList);
    //  System.out.println(exponentsList);

      Double[] coeffients = coeffientsList.toArray(new Double[coeffientsList.size()]);
      Double[] exponents = exponentsList.toArray(new Double[exponentsList.size()]);
      double lowerLimit = f.nextDouble();
      double upperLimit = f.nextDouble();
      double stepSize = f.nextDouble();f.nextLine();
      double cur = lowerLimit;
      double sum = 0.0;
      while(cur < upperLimit) {
        double functionValue = 0.0;
        for(int i = 0; i < coeffients.length; i++) {
          functionValue += Math.pow(cur, exponents[i]) * coeffients[i];
          //System.out.println(functionValue);
        }
        sum += functionValue * stepSize;
        cur += stepSize;
        //System.out.println(sum);
      }

      System.out.printf("%.2f\n", sum);
    }
  }
}
