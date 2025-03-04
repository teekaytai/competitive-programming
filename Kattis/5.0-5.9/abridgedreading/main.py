n, m = map(int, input().split())
a = []
while len(a) < n: a.extend(map(int, input().split()))
g = [[] for _ in range(n)]
ps = [-1] * n
ind = [0] * n
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1; v -= 1
    g[u].append(v)
    ps[v] = u
    ind[v] += 1
q = [i for i in range(n) if ind[i] == 0]
b = []
for u in q:
    if not g[u]: b.append(u)
    for v in g[u]:
        q.append(v)
q.reverse()
INF = 100000000
ans = INF
for s in b:
    ds = [INF] * n
    t = 0
    mn = INF
    c = s
    while c != -1:
        ds[c] = 0
        t += a[c]
        c = ps[c]
    for u in q:
        if ds[u] == 0: continue
        if ds[u] == INF: ds[u] = 0
        p = ps[u]
        if p == -1 or ds[p] == 0: mn = min(mn, ds[u] + a[u])
        else: ds[p] = min(ds[p], ds[u] + a[u])
    ans = min(ans, t + mn)
print(ans)
