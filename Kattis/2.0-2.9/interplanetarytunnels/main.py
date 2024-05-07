n, m = map(int, input().split())
s, t = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
q = [s]
seen = [False] * n
seen[s] = True
i = 0
while q:
    i += 1
    nq = []
    for u in q:
        for v in g[u]:
            if seen[v]: continue
            if v == t: print((i+1) // 2); exit()
            seen[v] = True
            nq.append(v)
    q = nq
