from heapq import *
while True:
    n, m = map(int, input().split())
    if not n: break
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        g[u].append((w, u, v))
        g[v].append((w, v, u))
    seen = [False] * n
    seen[0] = True
    pq = [*g[0]]
    edges = []
    cost = 0
    heapify(pq)
    while pq:
        w, u, v = heappop(pq)
        if seen[v]: continue
        seen[v] = True
        edges.append(sorted((u, v)))
        cost += w
        for w2, _, v2 in g[v]:
            if not seen[v2]:
                heappush(pq, (w2, v, v2))
    if len(edges) < n - 1:
        print('Impossible')
    else:
        print(cost)
        for e in sorted(edges):
            print(*e)
