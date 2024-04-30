import sys

input = lambda: sys.stdin.readline().strip()

n, t = map(int, input().split())
ta = 0
td = 0
A = []
C = []
D = []
for _ in range(n):
    a, b, d = map(int, input().split())
    A.append(a)
    C.append(b-a)
    D.append(d)
    ta += a
    td += d
X = [t * d / td - a for a, d in zip(A, D)]
t -= ta
lo = -1000000
hi = 1000000
while hi - lo > 1e-13:
    mid = (lo + hi) / 2
    s = sum(min(c, max(mid*d+x, 0)) for c, d, x in zip(C, D, X))
    if s < t:
        lo = mid
    else:
        hi = mid
for a, c, d, x in zip(A, C, D, X):
    print(a + min(c, max(lo*d+x, 0)))
