import sys

input = lambda: sys.stdin.readline().strip()

INF = 100000000

while True:
    n, m, q = map(int, input().split())
    if not n: break
    dp = [[INF] * n for _ in range(n)]
    for v in range(n):
        dp[v][v] = 0
    for _ in range(m):
        u, v, w = map(int, input().split())
        dp[u][v] = min(dp[u][v], w)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dp[i][k] < INF and dp[k][j] < INF:
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if dp[i][k] < INF and dp[k][j] < INF and dp[k][k] < 0:
                    dp[i][j] = -INF
                    break
    for _ in range(q):
        u, v = map(int, input().split())
        print("Impossible" if dp[u][v] == INF else "-Infinity" if dp[u][v] == -INF else dp[u][v])
    print()
