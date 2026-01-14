from itertools import accumulate
n, T, *a = map(int, open(0).read().split())
a.sort()
ps = list(accumulate(a))
lo = 1
hi = ps[-1] + 1
while lo < hi:
    mid = (lo + hi) // 2
    if sum(x // mid for x in ps) < T:
        hi = mid
    else:
        lo = mid + 1
print(lo)
