from heapq import *
DIRS = [(0, 1), (0, -1), (1, 0), (-1, 0)]
h, w = map(int, input().split())
g = [[*map(int, input().split())] for _ in range(h)]
pq = [(0, 0, 0)]
seen = [[False] * w for _ in range(h)]
while pq:
    d, r, c = heappop(pq)
    if seen[r][c]: continue
    seen[r][c] = True
    if r==h-1 and c==w-1: print(d); break
    for dr, dc in DIRS:
        r2 = r + dr
        c2 = c + dc
        if 0<=r2<h and 0<=c2<w and not seen[r2][c2]:
            heappush(pq, (max(d, g[r2][c2] - g[r][c]), r2, c2))
