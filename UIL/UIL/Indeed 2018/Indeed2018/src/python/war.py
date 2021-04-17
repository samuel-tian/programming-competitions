# level ? (1 = hard 10 = trivial)
from itertools import chain, combinations

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)  # allows duplicate elements
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

fh = open("judges/war.dat")
testcases = int(fh.readline().strip())
    
for testcase in range(0,testcases):
   honorable = False
   enemy = int(fh.readline().strip())
   #print(testcase,enemy)
   regimentsLine = fh.readline().strip()
   # regiments = [int(x) for x in regimentsLine.split()]
   regiments = []
   for regiment in regimentsLine.split():
      regiment = int(regiment)
      #if regiment <= enemy:
      regiments.append(regiment)
   for combo in powerset(regiments):
      if sum(combo) == enemy:
         honorable = True
         break
   if honorable:
      print("HONOR")
   else:
      print("DISHONOR")
  
       
