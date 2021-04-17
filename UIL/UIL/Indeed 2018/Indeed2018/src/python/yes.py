# level 6 (1 = hard 10 = trivial)
fh = open("judges/yes.dat")

testcases = int(fh.readline().strip())
    
for testcase in range(testcases):
   ELECTION = {}
   caesar = False
   voters = int(fh.readline().strip())
   for voter in range(voters):
      name,vote = fh.readline().strip().split(" ")
      #print(name,vote)
      if name == "caesar":
         caesar = True
         break
      ELECTION[name] = vote
   if caesar:
      if vote == "Y":
         print("YES")
      else:
         print("No")
   else:
      yes = 0
      no = 0
      for vote in list(ELECTION.values()):
         if vote == "Y":
            yes = yes + 1
         else:
            no = no + 1
      if yes > no:
         print("YES")
      elif yes < no:
         print("No")
      else:
         print("Tie")
      

   
