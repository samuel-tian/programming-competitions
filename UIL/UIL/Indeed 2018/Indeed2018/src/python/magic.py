fh = open("../../judges/magic.dat")

for line in fh:
    a,b,c,d,L = line.split(' ')
    a = int(a)
    b = int(b)
    c = int(c)
    d = int(d)
    L = int(L)
    count = 0
    if not (a==0 and b==0 and c==0 and d==0 and L==0):
       for num in range(0,L+1):
         calc = a*num**2 + b*num + c
         if calc % d == 0:
            count = count + 1
       print(count)

