def fact1(n):
    """ n: int > 0 """
    if n == 1:
        return 1
    else:
        n*fact1(n-1)

def fact2(n):
    """ n: int > 0 """
    prod = 1
    for i in range(1,n+1):
        prod *= i
    return prod

print(fact1(3))