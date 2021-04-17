fh = open("judges/hand.dat")

lines = int(fh.readline().strip())
   

for line in range(0,lines):
   knights = int(fh.readline().strip())
   #print("knights =",knights)
   a = 1
   b = 1
   cnt = 0
   while True:
      c = a + b
      #print(a,'+',b,'=',c)
      if c > knights:
         break
      cnt = cnt + 1
      a = b
      b = c
   print(cnt)
