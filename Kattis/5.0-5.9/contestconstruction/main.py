I = open(0)
n, m = map(int, next(I).split())
a = sorted(map(int, I))
dp = [[[0] * m for _ in range(n)] for _ in range(n)]
ans = 0
for i, x in enumerate(a):
    for j in range(i):
        t = x + a[j]
        dp[j][i][0] = 1
        for k in range(i, n):
            if a[k] > t: break
            for l in range(m - 1):
                dp[i][k][l + 1] += dp[j][i][l]
        ans += dp[j][i][m - 2]
print(ans)
