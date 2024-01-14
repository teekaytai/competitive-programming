import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n = int(input())
    lo = 0
    hi = 10000000000
    A = []
    for i in range(n):
        a, v = map(int, input().split())
        if a == 1:
            lo = max(lo, v)
        elif a == 2:
            hi = min(v, hi)
        else:
            A.append(v)
    print(hi - lo + 1 - sum(lo<=v<=hi for v in A) if lo <= hi else 0)
