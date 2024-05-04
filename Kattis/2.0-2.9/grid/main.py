DIRS = [(0, 1), (0, -1), (1, 0), (-1, 0)]
n, m = map(int, input().split())
g = [[int(x) for x in input()] for _ in range(n)]
seen = [[False] * m for _ in range(n)]
seen[0][0] = True
q = [(0, 0)]
i = 0
while q:
    i += 1
    nq = []
    for r, c in q:
        k = g[r][c]
        for dr, dc in DIRS:
            r2 = r + k*dr
            c2 = c + k*dc
            if 0<=r2<n and 0<=c2<m and not seen[r2][c2]:
                seen[r2][c2] = True
                if r2 == n-1 and c2 == m-1:
                    print(i)
                    exit()
                nq.append((r2, c2))
    q = nq
print(-1)
