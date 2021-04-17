# level ? (1 = hard 10 = trivial)

# CODE DOES NOT SOLVE PROBLEM CORRECTLY
fh = open("vault.dat")

testcases = int(fh.readline().strip())
    
for testcase in range(testcases):
   numRiches,maxWeight = fh.readline().strip().split(" ")
   numRiches = int(numRiches)
   maxWeight = int(maxWeight)
   riches = fh.readline().strip()
   richesList = [int(x) for x in riches.split()]
   weights = fh.readline().strip()
   weightsList = [int(x) for x in weights.split()]
   stats = []
   for i in range(len(richesList)):
     stats.append((richesList[i]/weightsList[i],richesList[i],weightsList[i]))
   stats.sort(reverse=True)
   totalWeight = 0
   totalRiches = 0
   for i in range(len(richesList)):
      weight = weightsList[i]
      if totalWeight + weight <= maxWeight:
         totalRiches = totalRiches + richesList[i]
   print(totalRiches)
         
   
