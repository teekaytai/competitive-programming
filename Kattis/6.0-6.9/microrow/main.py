import bisect
n = int(input())
a = [tuple(map(int, input().split())) for _ in range(n)]
I = sorted(range(n), key=a.__getitem__)
b = []
ans = [0] * n
for i in I:
    s = a[i][1]
    j = bisect.bisect_left(b, -s)
    ans[i] = j + 1
    if len(b) == j: b.append(-s)
    else: b[j] = -s
print(*ans)
