n, m, *a = map(int, open(0).read().split())
m += 1
lo = 0
hi = max(a) * (m // n + 1)
while lo < hi:
    mid = (lo + hi) // 2
    if sum(map(mid.__floordiv__, a)) < m: lo = mid + 1
    else: hi = mid
print(lo)
