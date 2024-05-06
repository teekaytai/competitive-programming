from math import comb
from itertools import product
for tc in range(1, int(input())+1):
    n, a, b, c, d, x, y, m = map(int, input().split())
    t = [[0]*3 for _ in range(3)]
    for i in range(n):
        t[x%3][y%3] += 1
        x = (a*x + b) % m
        y = (c*y + d) % m
    s = 0
    s2 = 0
    P = list(product(range(3), repeat=2))
    for p1 in P:
        i, j = p1
        s += comb(t[i][j], 3)
        for p2 in P:
            if p2 == p1: continue
            k, l = p2
            if (2*i+k)%3==0 and (2*j+l)%3==0: s += comb(t[i][j], 2) * t[k][l]
            for p3 in P:
                if p3 == p1 or p3 == p2: continue
                x, y = p3
                if (i+k+x)%3==0 and (j+l+y)%3==0: s2 += t[i][j] * t[k][l] * t[x][y]
    print(f'Case #{tc}:', s+s2//6)
