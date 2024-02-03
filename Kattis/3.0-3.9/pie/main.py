from math import pi
tcs = int(input())
for tc in range(tcs):
    n, f = map(int, input().split())
    *a, = map((2).__rpow__, map(int, input().split()))
    lo = 0
    hi = max(a)
    while hi - lo > 0.00001:
        mid = (lo + hi) / 2
        t = sum(r2 // mid for r2 in a)
        if t >= f+1:
            lo = mid
        else:
            hi = mid
    print(pi * lo)
