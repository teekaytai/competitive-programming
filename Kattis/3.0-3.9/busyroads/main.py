from heapq import *
import sys

input = lambda: sys.stdin.readline().strip()

n, m, c = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v, w, l, r = map(int, input().split())
    u -= 1; v -= 1
    g[u].append((v, w, l, r))
    g[v].append((u, w, l, r))
pq = [(0, 0)]
visited = [False] * n
while pq:
    d, u = heappop(pq)
    if visited[u]: continue
    visited[u] = True
    if u == n - 1: print(d); break
    for v, w, l, r in g[u]:
        if visited[v]: continue
        d2 = d + w
        if not l <= d % c <= r:
            d2 += (l - d) % c
        heappush(pq, (d2, v))
