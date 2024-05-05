from heapq import *
while True:
    n, m, q, s = map(int, input().split())
    if not n: break
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v, t, p, w = map(int, input().split())
        g[u].append((v, t, p, w))
    INF = 100000000
    ds = [INF] * n
    pq = [(0, s)]
    while pq:
        d, u = heappop(pq)
        if ds[u] != INF: continue
        ds[u] = d
        for v, t, p, w in g[u]:
            if ds[v] != INF: continue
            if p == 0 and d > t: continue
            d2 = t if d <= t else d + (t - d) % p
            heappush(pq, (d2 + w, v))
    for _ in range(q):
        d = ds[int(input())]
        print(d if d != INF else 'Impossible')
    print()
