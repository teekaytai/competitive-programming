from heapq import *
n, s, t = map(int, input().split())
g = [[int(x) for x in input().split()] for _ in range(n)]
seen = [False] * n
pq = [(0, s)]
while pq:
    d, u = heappop(pq)
    if seen[u]: continue
    seen[u] = True
    if u == t: print(d); break
    for v in range(n):
        if seen[v]: continue
        heappush(pq, (d + g[u][v], v))
