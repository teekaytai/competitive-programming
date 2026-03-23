n, m, s = map(int, input().split())
t = sum(sorted(map(int, input().split()))[:n-s])
d = [[1000000000] * n for _ in range(n)]
for i in range(n): d[i][i] = 0
for _ in range(m):
    u, v, w = map(int, input().split())
    u -= 1; v -= 1
    w = min(w, d[u][v])
    d[u][v] = w
    d[v][u] = w
for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])
dp = [[100000000] * 2**(n-1) for _ in range(n - 1)]
for i in range(n - 1): dp[i][0] = 0
for i in range(1, 2**(n-1)):
    ma = i
    while ma:
        b = ma & -ma
        ma ^= b
        bi = b.bit_length()
        dp[bi - 1][i] = min(d[bi][j + 1] + dp[j][i ^ b] for j in range(n - 1))
print(t + min((d[0][j + 1] + dp[j][-1] for j in range(n - 1)), default=0))
