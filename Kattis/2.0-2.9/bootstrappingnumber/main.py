n = int(input())
lo = 1.
hi = 10.
while hi-lo > 1e-7:
    mid = (lo + hi) / 2
    if mid**mid < n:
        lo = mid
    else:
        hi = mid
print(lo)
