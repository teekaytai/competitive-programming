import math
for _ in range(int(input())):
    r, n = map(int, input().split())
    *a, = [tuple(map(int, input().split())) for _ in range(n)]
    a.append(a[0])
    d = sum(math.dist(p,q) for p,q in zip(a, a[1:]))
    x = 1 - 2*math.pi*r/d
    print('Not possible' if x <= 0 else x)
