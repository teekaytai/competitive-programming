from itertools import combinations, starmap
from math import *
n = int(input())
ls = []
for _ in range(n):
    x1, y1, x2, y2 = map(float, input().split())
    ls.append(((m:=-(y1-y2)/(x1-x2)), 1.0, -(m * x1) - y1) if x1!=x2 else (1.0, 0.0, -x1))
mx = -1.0
EPS = 1e-7
def parallel(l1, l2):
    return abs(l1[0] - l2[0]) < EPS and abs(l1[1] - l2[1]) < EPS
def intersection(l1, l2):
    x = (l2[1]*l1[2] - l1[1]*l2[2]) / (l2[0]*l1[1] - l1[0]*l2[1])
    y = -(l1[0]*x + l1[2]) if l1[1] else -(l2[0]*x + l2[2])
    return x, y
for l1, l2, l3 in combinations(ls, 3):
    if any(parallel(l1, l2) for l1, l2 in combinations((l1, l2, l3), 2)): continue
    p1 = intersection(l1, l2)
    p2 = intersection(l2, l3)
    p3 = intersection(l3, l1)
    if all(isclose(p1[0], p2[0], rel_tol=EPS, abs_tol=EPS) and isclose(p1[1], p2[1], rel_tol=EPS, abs_tol=EPS) for p1, p2 in combinations((p1, p2, p3), 2)): continue
    mx = max(mx, sum(starmap(dist, combinations((p1, p2, p3), 2))))
print(mx if mx > -1.0 else 'no triangle')
