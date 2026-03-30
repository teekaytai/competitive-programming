n, m, s, t = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
dp = [0] * n
dp[s] = 1
for _ in range(t):
    dp = [sum(dp[v] for v in g[u]) for u in range(n)]
print(sum(dp))
