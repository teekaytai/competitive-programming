
s, n, m, p, *a = map(int, open(0).read().split())
n -= 1
m -= 1
ps = [0]
ans = [0, 0]
for x in a:
    ps.append(ps[-1] + (x > p))
    ans[0] += len(ps) > 2 * n and ps[-n - 1] - ps[-2 * n - 1] == n and ps[-1] == ps[-n - 1]
    ans[1] += len(ps) > 2 * m and ps[-m - 1] == ps[-2 * m - 1] and ps[-1] - ps[-m - 1] == m
    p = x
print(*ans)
