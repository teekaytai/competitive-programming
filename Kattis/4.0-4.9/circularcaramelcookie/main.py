n = int(input())
lo = 1.0
hi = int(((n + 4) // 2) ** .5) + 1
while hi - lo > 1e-7:
    mid = (lo + hi) / 2
    r2 = mid * mid
    h = int(mid)
    j = h
    t = 0
    for i in range(1, h + 1):
        i2 = i * i
        while j * j + i2 > r2:
            j -= 1
        t += j
    if t * 4 >= n + 1:
        hi = mid
    else:
        lo = mid
print((lo + hi) / 2)
