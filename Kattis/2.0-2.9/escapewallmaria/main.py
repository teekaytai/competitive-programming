Z = 'UDLR'
DIRS = [(1, 0), (-1, 0), (0, 1), (0, -1)]
t, n, m = map(int, input().split())
g = []
seen = [[False]*m for _ in range(n)]
q = []
for r in range(n):
    row = input()
    if (c:=row.find('S'))>-1: q.append((r, c)); seen[r][c] = True
    g.append(row)
for i in range(t+1):
    if not q: break
    nq = []
    for r, c in q:
        for d in range(4):
            dr, dc = DIRS[d]
            r2 = r + dr
            c2 = c + dc
            if r2 < 0 or r2 >= n or c2 < 0 or c2 >= m:
                print(i)
                exit()
            cell = g[r2][c2]
            if not seen[r2][c2] and (cell == '0' or cell == Z[d]):
                seen[r2][c2] = True
                nq.append((r2, c2))
    q = nq
print('NOT POSSIBLE')
