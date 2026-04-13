from math import cosh, sinh
d, s = map(int, input().split())
lo = 0.0
hi = 125000.0
while hi - lo > 1e-12:
    mid = (lo + hi) / 2
    if mid * cosh(d / 2 / mid) - mid > s:
        lo = mid
    else:
        hi = mid
print((lo + hi) * sinh(d / (lo + hi)))
