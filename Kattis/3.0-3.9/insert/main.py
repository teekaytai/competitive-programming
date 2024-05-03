from math import comb
def f(a):
    if len(a) <= 1: return 1
    b = []
    c = []
    for x in a[1:]:
        if x >= a[0]: b.append(x)
        else: c.append(x)
    return comb(len(a)-1, len(b)) * f(b) * f(c)
while n:=int(input()):
    *a, = map(int, input().split())
    print(f(a))
