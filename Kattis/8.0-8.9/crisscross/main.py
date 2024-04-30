from fractions import *
from itertools import combinations, starmap

def parallel(l1, l2):
    return l1[0] == l2[0] and l1[1] == l2[1]
def intersection(l1, l2):
    if parallel(l1, l2):
        if l1[2] != l2[2]: return None
        if l1[1] == 0:
            if l1[5] == l2[6]: return (l1[3], l1[5])
            if l1[6] == l2[5]: return (l1[3], l1[6])
            if l1[5] > l2[6] or l1[6] < l2[5]: return None
        else:
            if l1[3] == l2[4]: return (l1[3], -l1[0]*l1[3]-l1[2])
            if l1[4] == l2[3]: return (l1[4], -l1[0]*l1[4]-l1[2])
            if l1[3] > l2[4] or l1[4] < l2[3]: return None
        print(-1); exit()
    x = (l2[1]*l1[2] - l1[1]*l2[2]) / (l2[0]*l1[1] - l1[0]*l2[1])
    y = -(l1[0]*x + l1[2]) if l1[1] else -(l2[0]*x + l2[2])
    if l1[3] <= x <= l1[4] and l2[3] <= x <= l2[4] and l1[5] <= y <= l1[6] and l2[5] <= y <= l2[6]:
        return x, y

n = int(input())
ls = []
for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    mnx, mxx = sorted((x1, x2))
    mny, mxy = sorted((y1, y2))
    ls.append(((m := Fraction(y2-y1,x1-x2)), 1, -(m*x1)-y1, mnx, mxx, mny, mxy) if x1!=x2 else (1, 0, -x1, mnx, mxx, mny, mxy))
print(len(set(filter(None, starmap(intersection, combinations(ls, 2))))))
