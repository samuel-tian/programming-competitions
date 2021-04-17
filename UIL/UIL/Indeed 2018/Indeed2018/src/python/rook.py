# level 6 (1 = hard 10 = trivial)
fh = open("../../judges/rook.dat")

testcases = int(fh.readline().strip())
    
for testcase in range(testcases):
   rooks = int(fh.readline().strip())
   board = []
   for i in range(64):
      board.append('T')
   for x in range(rooks):
      rook = int(fh.readline().strip())
      space = rook - 1
      row = space // 8
      for bad in range(8*row,8*row+8):
         board[bad] = 'F'
      col = space % 8
      for bad in range(col,64,8):
         board[bad] = 'F'
   #print(board)
   good = 0
   for space in board:
      if space == 'T':
         good = good + 1
   print(good)

      
  

   
