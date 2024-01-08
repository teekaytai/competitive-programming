INF = float('inf')
while True:
    n, m, q, s = map(int, input().split())
    if n == 0: break
    adj = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        adj[u].append((v, w))

    d = [INF] * n
    d[s] = 0
    queue = [s]
    for _ in range(n):
        nq = []
        inq = [False] * n
        for u in queue:
            for v, w in adj[u]:
                d2 = d[u] + w
                if d2 < d[v]:
                    d[v] = d2
                    if not inq[v]:
                        inq[v] = True
                        nq.append(v)
        queue = nq
    for u in queue: d[u] = -INF
    while queue:
        u = queue.pop()
        for v, _ in adj[u]:
            if d[v] > -INF:
                d[v] = -INF
                queue.append(v)
    for _ in range(q):
        dist = d[int(input())]
        print('-Infinity' if dist == -INF else 'Impossible' if dist == INF else dist)
