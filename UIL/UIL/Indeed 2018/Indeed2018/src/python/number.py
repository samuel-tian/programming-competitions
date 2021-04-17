# level 6 (1 = hard 10 = trivial)
fh = open("../../judges/number.dat")

testcases = int(fh.readline().strip())

def convert(num,curVal,pre,rep,higher):
   num = num//curVal
   #print(num,curVal,pre,rep,higher)
   if num <= 3:
      roman = pre + rep * num
   else:
      roman = rep + higher
   return roman 
   

for testcase in range(testcases):
   #print("testcase",testcase)
   num = int(fh.readline().strip())
   #print(convert(num,5,'I','','V'))   # ones 1-4
   if num >= 1000:
      print(convert(num,1000,'','M',''),end="")     # 1000-3000
      num = num - (num//1000 * 1000)
   if num >= 500:
      print(convert(num-500,100,'D','C','M'),end="")   # 500-900
      num = num - (num//100 * 100)
   if num >= 100:
      print(convert(num,100,'','C','D'),end="")     # 100-400
      num = num - (num//100 * 100)
   if num >= 50:
      print(convert(num-50,10,'L','X','C'),end="")   # 50-90
      num = num - (num//10 * 10)
   if num >= 10:
      print(convert(num,10,'','X','L'),end="")     # 10-40
      num = num - (num//10 * 10)
   if num >= 5:
      print(convert(num-5,1,'V','I','X'),end="")   # 50-90
      num = 0
   if num >= 1:
      print(convert(num,1,'','I','V'),end="")     # 10-40
   print()

      

      
   
