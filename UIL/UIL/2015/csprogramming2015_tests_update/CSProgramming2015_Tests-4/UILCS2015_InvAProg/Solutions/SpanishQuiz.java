import java.util.*;
import java.lang.Integer;
import java.io.File;
import java.io.FileNotFoundException;

public class SpanishQuiz
{
    private static final Map<String, String> cityCountryMap = new HashMap<String, String>();
    static
    {
        cityCountryMap.put("Mexico D.F.", "Mexico");
        cityCountryMap.put("Guatemala", "Guatemala");
        cityCountryMap.put("Tegucigalpa", "Honduras");
        cityCountryMap.put("San Salvador", "El Salvador");
        cityCountryMap.put("Managua", "Nicaragua");
        cityCountryMap.put("San Jose", "Costa Rica");
        cityCountryMap.put("Panama", "Panama");
        cityCountryMap.put("Caracas", "Venezuela");
        cityCountryMap.put("Bogota", "Colombia");
        cityCountryMap.put("Quito", "Ecuador");
        cityCountryMap.put("Lima", "Peru");
        cityCountryMap.put("La Paz", "Bolivia");
        cityCountryMap.put("Asuncion", "Paraguay");
        cityCountryMap.put("Santiago", "Chile");
        cityCountryMap.put("Buenos Aires", "Argentina");
        cityCountryMap.put("Montevideo", "Uruguay");
        cityCountryMap.put("Brasilia", "Brazil");
    }

    private static final Map<String, String> countryCityMap = new HashMap<String, String>();
    static
    {
        countryCityMap.put("Mexico", "Mexico D.F.");
        countryCityMap.put("Guatemala", "Guatemala");
        countryCityMap.put("Honduras", "Tegucigalpa");
        countryCityMap.put("El Salvador", "San Salvador");
        countryCityMap.put("Nicaragua", "Managua");
        countryCityMap.put("Costa Rica", "San Jose");
        countryCityMap.put("Panama", "Panama");
        countryCityMap.put("Venezuela", "Caracas");
        countryCityMap.put("Colombia", "Bogota");
        countryCityMap.put("Ecuador", "Quito");
        countryCityMap.put("Peru", "Lima");
        countryCityMap.put("Bolivia", "La Paz");
        countryCityMap.put("Paraguay", "Asuncion");
        countryCityMap.put("Chile", "Santiago");
        countryCityMap.put("Argentina", "Buenos Aires");
        countryCityMap.put("Uruguay", "Montevideo");
        countryCityMap.put("Brazil", "Brasilia");
    }

    public static void main(String[] args)
    {
        String answer = "Signs point to no.";
        Scanner scan = null;

        try
        {
            if(args.length > 0)
                scan = new Scanner(new File(args[0]));
            else
                scan = new Scanner(new File("spanishquiz.dat"));
        } 
        catch (FileNotFoundException e)
        {
            System.out.println("File not found!");
            return;
        }

        assert(scan.hasNext());
        
        // Get the number of lines, and continue to next line of input.
        final int numQuestions = Integer.parseInt(scan.next());
        scan.nextLine();

        String[] line;
        for(int i = 0; i < numQuestions; ++i)
        {
            line = scan.nextLine().split(" is the capital city of ");
            System.out.println(getAnswer(line));
        }
    }

    private static String getAnswer(String[] line)
    {
        String city;
        String country;

        if(line[0].equals("What"))
        {
            country = line[1].substring(0, line[1].length() - 1);
            city = countryCityMap.get(country);
        }
        else
        {
            city = line[0];
            country = cityCountryMap.get(city);
        }

        return city + " is the capital city of " + country + ".";
    }
}
