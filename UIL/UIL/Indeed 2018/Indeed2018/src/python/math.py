fh = open("judges/math.dat")

lines = int(fh.readline().strip())

for line in range(0,lines):
   line = fh.readline().strip()
   parenFound = True
   while parenFound:
      pos = 0
      parenFound = False
      for char in line:
         if char == "(":
            start = pos
            parenFound = True
         elif char == ")":
            stop = pos
            beg = ""
            end = ""
            if start > 0:
               beg = line[0:start]
            if stop < len(line)-1:
               end = line[stop+1:]
            line = beg + str(eval(line[start+1:stop])) + end
            pos = 0
            break
         pos = pos + 1

   #print(eval(line))
   #print(str(round(eval(line),2)))
   print('{:.2f}'.format(round(eval(line),2)))

   
