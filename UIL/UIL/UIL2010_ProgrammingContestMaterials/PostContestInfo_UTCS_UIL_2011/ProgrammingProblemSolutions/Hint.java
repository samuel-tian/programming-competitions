import java.io.*;
import java.util.*;

public class Hint {
    public static void main(String[] args) throws IOException{
        System.out.println("import java.io.*;");
        System.out.println("import java.util.*;");
        System.out.println("public class template {");
        System.out.println("    public static void main(String[] args) throws IOException{");
        System.out.println("        Scanner s = new Scanner(new File(\"hint.dat\"));");
        System.out.println("        int numSets = s.nextInt();");
        System.out.println("        s.nextLine();");
        System.out.println("        for(int i = 1; i <= numSets; i++){");
        System.out.println("            //do stuff for data set");
        System.out.println("        }");
        System.out.println("        s.close();");
        System.out.println("    }");
        System.out.println("}");
    }
}
