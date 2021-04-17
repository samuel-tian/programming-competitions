// Mole Day.

import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

class Isabella {
  public static void main(String [] args) throws FileNotFoundException {
    Scanner f = new Scanner(new File("isabella.dat"));
    int q = f.nextInt();f.nextLine();
    HashMap<String, BigDecimal> rates = new HashMap<>();
    while(q-- > 0) {
      String startMoney = f.next();
      String endMoney = f.next();
      BigDecimal rate = new BigDecimal(f.next());
      rates.put(startMoney + endMoney, rate);
    }
    int N = f.nextInt();f.nextLine();
    while(N-- > 0) {
      int p = f.nextInt();f.nextLine();
      ArrayList<MoneyValue> payroll = new ArrayList<>();
      while(p-- > 0) {
        BigDecimal value = new BigDecimal(f.next());
        String currency = f.next();
        payroll.add(new MoneyValue(value, currency));
      }
      MoneyValue finalValue = new MoneyValue(new BigDecimal(f.next()), f.next());
      String resultCurrency = finalValue.currency;
      BigDecimal sum = new BigDecimal(0.0);
      for(MoneyValue mv: payroll) {
        BigDecimal factor = new BigDecimal(1.0);
        if(!mv.currency.equals(resultCurrency)) {
          factor = rates.get(mv.currency + resultCurrency);
        }
        sum = sum.add(factor.multiply(mv.value));
      //  System.out.println(sum);
      }
      if(finalValue.value.compareTo(sum) == 0) {
        System.out.println("GOOD LEDGER");
      } else {
        System.out.println("BAD LEDGER");
      }
    }
  }
}

class MoneyValue {
  public BigDecimal value;
  public String currency;
  public MoneyValue(BigDecimal value, String currency) {
    this.value = value;
    this.currency = currency;
  }
  public String toString() {
    return value.toString() + " " + currency;
  }
}
