n = int(input())
*a, = map(int, input().split())
ans = []
for x in a:
    lo = 0
    hi = len(ans)
    while lo < hi:
        mid = (lo + hi) // 2
        if ans[mid][-1] >= x:
            lo = mid + 1
        else:
            hi = mid
    if lo == len(ans): ans.append([x])
    else: ans[lo].append(x)
print(len(ans))
for r in ans: print(*r)
