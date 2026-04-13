from collections import Counter
from math import *
while True:
    n = int(input())
    if not n: break
    ps = [tuple(map(int, input().split())) for _ in range(n)]
    mx = 1
    for i, (x1, y1) in enumerate(ps):
        C = Counter()
        for j in range(i+1, n):
            x2, y2 = ps[j]
            if x1 == x2: C[(1, 0)] += 1
            else:
                dx = x2-x1
                a = y1-y2
                b = dx
                g = copysign(gcd(a, b), a)
                C[(a//g, b//g)] += 1
        if not C: continue
        mx = max(mx, C.most_common(1)[0][1] + 1)
    print(mx)
