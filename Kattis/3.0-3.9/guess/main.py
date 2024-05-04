lo = 1
hi = 1000
while lo < hi:
    mid = (lo + hi) // 2
    print(mid, flush=True)
    cmp = input()
    if cmp == 'correct': break
    if cmp == 'lower':
        hi = mid - 1
    else:
        lo = mid + 1
else:
    print(lo, flush=True)
