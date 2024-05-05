from heapq import *
while True:
    n, m, q, s = map(int, input().split())
    if not n: break
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        g[u].append((v, w))
    INF = 100000000
    ds = [INF] * n
    pq = [(0, s)]
    while pq:
        d, u = heappop(pq)
        if ds[u] != INF: continue
        ds[u] = d
        for v, w in g[u]:
            if ds[v] != INF: continue
            heappush(pq, (d+w, v))
    for _ in range(q):
        d = ds[int(input())]
        print(d if d != INF else 'Impossible')
    print()
