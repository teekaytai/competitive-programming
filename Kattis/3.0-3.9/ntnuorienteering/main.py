def main():
    c = int(input())
    n = int(input())
    g = [[0] * c for _ in range(c)]
    for _ in range(c * (c - 1) // 2):
        u, v, w = map(int, input().split())
        g[u][v] = w
        g[v][u] = w
    for k in range(c):
        for i in range(c):
            for j in range(c):
                g[i][j] = min(g[i][j], g[i][k] + g[k][j])
    a = []
    for _ in range(n):
        k, l, r = map(int, input().split())
        a.append((l, r, k))
    a.sort()
    dp = [0] * n
    for i in range(n):
        l, r, k = a[i]
        for j in range(i + 1, n):
            if r + g[k][a[j][2]] <= a[j][0]:
                dp[j] = max(dp[j], dp[i] + 1)
    print(max(dp) + 1)

tcs = int(input())
for tc in range(tcs):
    main()
