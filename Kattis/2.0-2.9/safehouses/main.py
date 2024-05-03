DIRS = [(0, 1), (0, -1), (1, 0), (-1, 0)]
n = int(input())
g = [input() for _ in range(n)]
s = sum(row.count('S') for row in g)
q = [(r, c) for r in range(n) for c in range(n) if g[r][c] == 'H']
seen = [[cell == 'H' for cell in row] for row in g]
i = 0
while s:
    i += 1
    nq = []
    for r, c in q:
        for dr, dc in DIRS:
            r2 = r + dr
            c2 = c + dc
            if 0<=r2<n>c2>=0 and not seen[r2][c2]:
                seen[r2][c2] = True
                nq.append((r2, c2))
                s -= g[r2][c2] == 'S'
    q = nq
print(i)
