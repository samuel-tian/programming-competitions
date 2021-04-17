/*
UIL 2017 - Owen Solution

Invitational B
Danna - Math processing needing accumulation array

At a recent visit to her doctor, Danna was informed of her BMI (Body Mass Index), 
a calculation based on her height and weight (BMI = kg/m2), and was told she was classified as 
marginally overweight (height 5’10”, weight 175 lbs), which surprised her a bit.  
She did not consider herself overweight, and decided to do more research.  
She discovered that BMI was a weight-to-height ratio, calculated by dividing one's weight in 
kilograms by the square of one's height in meters and is used as an indicator of obesity and underweight. 
She also discovered that the scale was different for women than men.  

According to an online source she found during her research (http://halls.md/bmi-chart-women/), 
BMI is used as a screening tool to identify possible weight problems for adults. However, 
body mass index is not a diagnostic tool. To determine if excess weight is a health risk, 
a healthcare provider would need to perform further assessments. Danna also found that calculating 
BMI is one of the best methods for population assessment of overweight and obesity, but was not 
really the most appropriate method for individual diagnosis, which relieved her somewhat.

She decided to do some research at her school using the parameters she discovered for young women around her age, 
which stipulated that a BMI under 18.5 is considered very underweight and possibly malnourished, 18.5-24.9 is a 
healthy weight range, 25.0 to 29.9 is considered overweight and over 30 is considered obese. 
She asked female students she knew in her classes in school for their anonymous participation, 
which many did by providing their height and weight on notecards, but without providing their name.  

She then processed the data, classifying each person’s BMI individually, and then doing an overall report, 
showing how many fell into each category, based on the parameters listed above, and solely based on height 
in inches and weight in pounds. She used the conversion values of 1 inch = 0.0254 meters and 
1 pound = 0.453592 kilograms to convert the notecard data to metric units. For example, 
her own data was 70 inches and 175 pounds, which converted to 1.778 meters and 79.3786 kilograms, 
which then produced a BMI of 25.11 (79.3786/1.7782), putting her on the borderline just into the 
“overweight” category. Another person’s data reported in the “underweight” category with a height 
and weight of 68 inches and 105 pounds, for a BMI of 15.97. 

She did this same calculation for all of the data set collected, reporting a list that contained 
the original data, the BMI index for each data set, and the corresponding classification. 
Finally, she took all of the results and calculated the percentage of how many of the students 
fell into each of the four categories.

Input: Several pairs of integers H and W, representing height in inches and weight in pounds, each pair on line.

Output: The original data for each set, H and W, the BMI calculation, expressed to a precision of two decimal places, 
and the corresponding classification, each output value separated by exactly one space. After the last data set report line, 
the total number of students surveyed is reported, followed by four lines, each showing the percentage for each classification, 
precise to one decimal place, in the same order as shown in the sample output.

 
Sample input:
70 175
68 105
63 110
60 130
65 130
68 115
66 120
61 170
72 125
64 135
70 140
Sample output:
70 175 25.11 overweight
68 105 15.97 underweight
63 110 19.49 normal
60 130 25.39 overweight
65 130 21.63 normal
68 115 17.49 underweight
66 120 19.37 normal
61 170 32.12 obese
72 125 16.95 underweight
64 135 23.17 normal
70 140 20.09 normal
11 total students surveyed
27.27% underweight
45.45% normal
18.18% overweight
9.09% obese

*/
import java.util.*;
import java.io.*;
import static java.lang.System.*;
class Danna
{
	public static void main(String [] args) throws IOException
	{
		Scanner f = new Scanner(new File("danna.dat"));
		int [] list = {0,0,0,0};
		String [] c = {"underweight","normal","overweight","obese"};
		int count = 0;
		while(f.hasNext())
		{
			count++;
			int ht = f.nextInt();
			int wt = f.nextInt();
			double m = ht*0.0254;
			double kg = wt*0.453592;
			double bmi = kg/(m*m);
			int b = bmi<18.5?0:bmi<25.0?1:bmi<30?2:3;
			String s = c[b];
			list[b]++;
			out.printf("%d %d %.2f %s\n",ht, wt, bmi,s);
		}
		f.close();
		out.printf("%d total students surveyed\n", count);
		out.printf("%.2f%% %s\n",list[0]*100.0/count,c[0]);
		out.printf("%.2f%% %s\n",list[1]*100.0/count,c[1]);
		out.printf("%.2f%% %s\n",list[2]*100.0/count,c[2]);
		out.printf("%.2f%% %s\n",list[3]*100.0/count,c[3]);
	}
}
/*
Sample data
70 175
68 105
63 110
60 130
65 130
68 115
66 120
61 170
72 125
64 135
70 140

Sample output
70 175 25.11 overweight
68 105 15.97 underweight
63 110 19.49 normal
60 130 25.39 overweight
65 130 21.63 normal
68 115 17.49 underweight
66 120 19.37 normal
61 170 32.12 obese
72 125 16.95 underweight
64 135 23.17 normal
70 140 20.09 normal
11 total students surveyed
27.27% underweight
45.45% normal
18.18% overweight
9.09% obese

Test data
70 175
68 105
63 110
60 130
65 130
68 115
66 120
61 170
72 125
64 135
70 140
68 145
72 175
66 100
60 105
70 110
62 115
60 120
66 125
70 135
64 140
60 145
66 150
62 155
70 160
64 165
72 130
72 135
72 140
66 145
68 150
70 155
72 160
72 165
70 170
72 175
64 180
64 185
70 190
70 195
70 200
60 205
62 210
62 215

Test output
70 175 25.11 overweight
68 105 15.97 underweight
63 110 19.49 normal
60 130 25.39 overweight
65 130 21.63 normal
68 115 17.49 underweight
66 120 19.37 normal
61 170 32.12 obese
72 125 16.95 underweight
64 135 23.17 normal
70 140 20.09 normal
68 145 22.05 normal
72 175 23.73 normal
66 100 16.14 underweight
60 105 20.51 normal
70 110 15.78 underweight
62 115 21.03 normal
60 120 23.44 normal
66 125 20.18 normal
70 135 19.37 normal
64 140 24.03 normal
60 145 28.32 overweight
66 150 24.21 normal
62 155 28.35 overweight
70 160 22.96 normal
64 165 28.32 overweight
72 130 17.63 underweight
72 135 18.31 underweight
72 140 18.99 normal
66 145 23.40 normal
68 150 22.81 normal
70 155 22.24 normal
72 160 21.70 normal
72 165 22.38 normal
70 170 24.39 normal
72 175 23.73 normal
64 180 30.90 obese
64 185 31.75 obese
70 190 27.26 overweight
70 195 27.98 overweight
70 200 28.70 overweight
60 205 40.04 obese
62 210 38.41 obese
62 215 39.32 obese
44 total students surveyed
15.91% underweight
52.27% normal
18.18% overweight
13.64% obese

*/