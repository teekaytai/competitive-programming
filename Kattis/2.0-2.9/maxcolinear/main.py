from math import *
while True:
    n = int(input())
    if not n: break
    ps = [tuple(map(int, input().split())) for _ in range(n)]
    mx = 1 + (n > 1)
    for i, (x1, y1) in enumerate(ps):
        if i == n-1: continue
        ms = [inf if ps[j][0] == x1 else (ps[j][1]-y1)/(ps[j][0]-x1) for j in range(i+1, n)]
        ms.sort()
        p = ms[0]
        r = 2
        for j in range(1, len(ms)):
            if ms[j] - p < 1e-9 or ms[j] == p == inf: r += 1; mx = max(mx, r)
            else: r = 2
            p = ms[j]
    print(mx)
