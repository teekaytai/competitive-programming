import sys

input = lambda: sys.stdin.readline().strip()
DIRS = [(-1, 0), (0, 1), (1, 0), (0, -1)]
NEG_INF = -100000000

n, f = map(int, input().split())
g = [(*map(int, input().split()),) for _ in range(n)]
dp = [[[NEG_INF]*(f+1) for _ in range(n)] for _ in range(n)]
order = [(v, r, c) for r, row in enumerate(g) for c, v in enumerate(row)]
order.sort()
for v, r, c in order:
    a = dp[r][c]
    if r==0 or c==0 or r==n-1 or c==n-1:
        a[0] = v
    for t in range(1, f+1):
        for dr, dc in DIRS:
            r2 = r + dr
            c2 = c + dc
            if 0<=r2<n>c2>=0 and g[r2][c2] < v:
                a[t] = max(a[t], dp[r2][c2][t-1]+v)
print(max(d for A in dp for B in A for d in B))
