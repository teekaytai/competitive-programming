n, k = map(int, input().split())
g = [[] for _ in range(n)]
t = 0
for _ in range(n-1):
    u, v, w = map(int, input().split())
    u -= 1; v -= 1
    g[u].append((v, w))
    g[v].append((u, w))
    t += w
if k >= 2: print(t); exit()
def dfs(r):
    s = [(r, 0, -1)]
    m = 0, r
    while s:
        u, d, p = s.pop()
        m = max(m, (d, u))
        for v, w in g[u]:
            if v == p: continue
            s.append((v, d+w, u))
    return m

print(dfs(dfs(0)[1])[0])
