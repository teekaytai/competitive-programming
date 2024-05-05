from heapq import *
import math
s = tuple(map(float, input().split()))
t = tuple(map(float, input().split()))
n = int(input())
g = [tuple(map(float, input().split())) for _ in range(n)]
g.append(t)
seen = [False] * (n+1)
pq = [(math.dist(s, p)/5, i) for i, p in enumerate(g)]
heapify(pq)
while pq:
    d, u = heappop(pq)
    if seen[u]: continue
    seen[u] = True
    if u == n: print(d); break
    p = g[u]
    for v, q in enumerate(g):
        if seen[v]: continue
        dd = math.dist(p, q)
        heappush(pq, (d + min(dd/5, 2+abs(dd-50)/5), v))
