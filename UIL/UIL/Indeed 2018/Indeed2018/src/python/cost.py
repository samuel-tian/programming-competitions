
fh = open("../../judges/cost.dat")
n = int(fh.readline())

count = 0
for i in range(n):
    count = count + 1
    a, b, c = fh.readline().strip().split(' ')
    a = int(a)
    b = int(b)
    c = int(c)
    cmp1 = a > b
    cmp2 = b > c
    cmp3 = a > c
    rslt = c
    if cmp1 != cmp3:
       rslt = a
    elif cmp1 == cmp2:
       rslt = b
    print("Case",str(count)+":",rslt)


