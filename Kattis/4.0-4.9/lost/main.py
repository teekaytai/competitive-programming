n, m = map(int, input().split())
n += 1
ls = {l: i for i, l in enumerate(input().split(), start=1)}
ls['English'] = 0
g = [[] for _ in range(n)]
for _ in range(m):
    ul, vl, w = input().split()
    u = ls[ul]
    v = ls[vl]
    w = int(w)
    g[u].append((v, w))
    g[v].append((u, w))
INF = float('inf')
ds = [INF] * n
mns = [INF] * n
q = [0]
ds[0] = 0
mns[0] = 0
i = 0
while q:
    i += 1
    q2 = []
    for u in q:
        for v, w in g[u]:
            if ds[v] < i:
                continue
            if ds[v] > i:
                ds[v] = i
                q2.append(v)
            mns[v] = min(mns[v], w)
    q = q2
t = sum(mns)
print(t if t < INF else 'Impossible')
