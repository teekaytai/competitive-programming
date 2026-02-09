n, m = map(int, input().split())
dp = [(-1000000, 0)] * (n + 1)
dp[0] = (0, 0)
for j in range(m + 1):
    k, *a = map(int, input().split())
    dp2 = [(-1000000, 0)] * (n + 1)
    for p, s in zip(a[:k], a[k:]):
        v = p * s
        for i in range(s, n):
            dp2[i] = max(dp2[i], (dp[i - s][0] + v, dp[i - s][1] if j > 0 else -p))
        dp2[-1] = max(dp2[-1], max((dp[n - i][0] + p * i, dp[n - i][1] if j > 0 else -p) for i in range(min(n, s) + 1)))
    dp = dp2
ans, p = max(dp)
print(ans)
print(-p)
