from heapq import *
DIRS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
n, m, k = map(int, input().split())
g = [input() for _ in range(n)]
sr, sc = next((r, c) for r in range(n) for c in range(m) if g[r][c] == 'S')
tr, tc = next((r, c) for r in range(n) for c in range(m) if g[r][c] == 'G')
D = 100000
pq = [(D, sr, sc)]
ds = [[float('inf')] * m for _ in range(n)]
ds[sr][sc] = D
while pq:
    d, r, c = heappop(pq)
    if ds[r][c] != d:
        continue
    if r == tr and c == tc:
        print(d // D)
        exit()
    for dr, dc in DIRS:
        r2 = r + dr
        c2 = c + dc
        if 0 <= r2 < n and 0 <= c2 < m and g[r2][c2] != '#':
            w = 3 if g[r2][c2] == 'M' else 2 if g[r2][c2] == 'F' else 1
            if w > k: continue
            d2 = d + w
            x = d2 % D
            if x > k:
                d2 += D - x + w
            if d2 < ds[r2][c2]:
                ds[r2][c2] = d2
                heappush(pq, (d2, r2, c2))
print(-1)
