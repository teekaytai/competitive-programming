import sys

input = lambda: sys.stdin.readline().strip()
INF = 100000000

n, m = map(int, input().split())
bks = []
vs = []
for _ in range(m):
    k, v = map(int, input().split())
    vs.append(v)
    B = []
    for _ in range(k):
        i, p = map(int, input().split())
        B.append([i-1, p])
    bks.append(B)

def dfs(i, ps, t):
    if i >= m:
        return t + sum(ps)
    mn = dfs(i+1, ps, t)
    t += vs[i]
    ps2 = ps.copy()
    for k, p in bks[i]: ps2[k] = min(ps2[k], p)
    return min(mn, dfs(i+1, ps2, t))

print(dfs(0, [INF]*n, 0))
