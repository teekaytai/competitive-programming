n = int(input())
lo = 1
hi = n
i = 0
while lo <= hi:
    mid = (lo + hi) // 2
    i += 1
    print(mid*i, flush=True)
    cmp = input()
    if cmp == 'exact': break
    if cmp == 'less': hi = mid - 1
    else: lo = mid + 1
