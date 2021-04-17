# level 7 (1 = hard 10 = trivial)
fh = open("judges/sort.dat")

lines = int(fh.readline().strip())
    

for line in range(0,lines):
   FOUND = {}
   line = fh.readline().strip()
   pieces = line.split(" ")
   # p b h r q k P B H R Q K
   for piece in pieces:
      if piece in FOUND:
         FOUND[piece] = FOUND[piece] + 1
      else:
         FOUND[piece] = 1
   first = True
   for piece in ['p','b','h','r','q','k','P','B','H','R','Q','K']:
      for x in range(FOUND.get(piece,0)):
         if first:
            print(piece,end="")
            first = False
         else:
            print(" " + piece,end="")
   print()
   
