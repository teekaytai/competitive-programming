import sys

input = lambda: sys.stdin.readline().strip()

DIRS = [(0, -1), (0, 1), (-1, 0), (1, 0)]
DIRS2 = [(0, -1), (0, 1), (-1, 0), (1, 0), (-1, -1), (-1, 1), (1, -1), (1, 1)]

n, m, q = map(int, input().split())
g = [input() for _ in range(n)]
sr, sc = next((r, c)for r, row in enumerate(g) if (c:=row.find('#'))>=0)

d = [[-1] * m for _ in range(n)]
queue = [(r, c) for r in range(n) for c in range(m) if g[r][c] == 'v']
for r, c in queue: d[r][c] = 0
i = 1
while queue:
    nq = []
    for r, c in queue:
        for dr, dc in DIRS:
            r2 = r + dr
            c2 = c + dc
            if 0<=r2<n and 0<=c2<m and d[r2][c2]<0:
                d[r2][c2] = i
                nq.append((r2, c2))
    queue = nq
    i += 1


def f(R, C, v):
    s = [(R, C)]
    reachable = [[False] * m for _ in range(n)]
    reachable[R][C] = True
    while s:
        r, c = s.pop()
        for dr, dc in DIRS:
            r2 = r + dr
            c2 = c + dc
            if 0<=r2<n and 0<=c2<m and g[r2][c2]!='#' and not reachable[r2][c2] and d[r2][c2] >= v:
                reachable[r2][c2] = True
                s.append((r2, c2))
    s = [(sr, sc)]
    while s:
        r, c = s.pop()
        for dr, dc in DIRS2:
            r2 = r + dr
            c2 = c + dc
            if 0<=r2<n and 0<=c2<m and not reachable[r2][c2]:
                if r2 == 0 or r2 == n-1 or c2 == 0 or c2 == m-1:
                    return False
                reachable[r2][c2] = True
                s.append((r2, c2))
    return True

for _ in range(q):
    R, C = map(int, input().split())
    R-=1
    C-=1
    lo = 0
    hi = d[R][C]
    while lo < hi:
        mid = lo + (hi - lo + 1) // 2
        if f(R, C, mid):
            lo = mid
        else:
            hi = mid - 1
    print(lo)
