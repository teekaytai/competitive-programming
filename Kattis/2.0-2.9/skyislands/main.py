n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1; v -= 1
    g[u].append(v)
    g[v].append(u)
s = [0]
seen = [False] * n
seen[0] = True
while s:
    u = s.pop()
    for v in g[u]:
        if not seen[v]:
            seen[v] = True
            s.append(v)
print(['NO','YES'][all(seen)])
