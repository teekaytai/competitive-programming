n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)
if all(len(vs) < 2 for vs in g):
    print(1)
    print(*range(1, n + 1))
    exit()
cs = [0] * n
for u in range(n):
    while u != -1:
        c = cs[u]
        x = sum(cs[v] == c for v in g[u])
        if x < 2:
            break
        cs[u] = 1 - cs[u]
        u = next((v for v in g[u] if cs[v] != c), default=-1)
print(2)
for i in range(2):
    print(*(v + 1 for v, c in enumerate(cs) if c == i))
