from functools import lru_cache
from heapq import *
import sys

input = lambda: sys.stdin.readline().strip()

n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    g[u].append((v, w))
    g[v].append((u, w))
s = int(input())
V = {int(input()): i for i in range(s)}
V[0] = s
ds = [[0] * (s+1) for _ in range(s+1)]
for r, i in V.items():
    c = s
    pq = [(0, r)]
    seen = [False] * n
    while pq:
        d, u = heappop(pq)
        if seen[u]: continue
        seen[u] = True
        if u != r and (j := V.get(u)) is not None:
            ds[i][j] = d
            c -= 1
            if not c: break
        for v, w in g[u]:
            if seen[v]: continue
            heappush(pq, (d + w, v))
@lru_cache(maxsize=None)
def dfs(i, S):
    if not S:
        return ds[i][-1]
    m = S
    mn = 100000000000000
    while m:
        b = m & -m
        m -= b
        j = b.bit_length() - 1
        mn = min(mn, ds[i][j] + dfs(j, S - b))
    return mn
print(dfs(s, (1<<s)-1))
