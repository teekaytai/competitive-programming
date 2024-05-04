n, h, l = map(int, input().split())
*q, = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(l):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
INF = 2000
d = [INF] * n
for v in q: d[v] = 0
while q:
    nq = []
    for u in q:
        for v in g[u]:
            if d[v] < INF: continue
            d[v] = d[u] + 1
            nq.append(v)
    q = nq
print(d.index(max(d)))
