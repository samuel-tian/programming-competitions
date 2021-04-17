# what are the only 4 digit numbers
# whose sum when you sum up each of its digits raised to the 7th power
# in octal is equal to the original number
#
#  1230 = 1^7 + 2^7 + 3^7 + 0^7 = 2316 = 2*512 + 3*64 + 1*8 + 6 = 1230
#  1231 = 1^7 + 2^7 + 3^7 + 1^7 = 2317 = 2*512 + 3*64 + 1*8 + 7 = 1231

found = 0
for num in range(1000,10000):
   numStr = str(num)
   sumNum = 0
   for digit in numStr:
     sumNum = sumNum + int(digit)**7
   sumNumStr = str(sumNum)
   octal = 0
   if len(sumNumStr) == 4:
      octal = int(sumNumStr[0])*512 + int(sumNumStr[1])*64 + int(sumNumStr[2])*8 + int(sumNumStr[3])
   elif len(sumNumStr) == 5:
      octal = int(sumNumStr[0])*4086 + int(sumNumStr[1])*512 + int(sumNumStr[2])*64 + int(sumNumStr[3])*8 + int(sumNumStr[4])   
   if num == octal:
      found = found + 1
      print(num)


