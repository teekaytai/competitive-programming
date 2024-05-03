h, w = map(int, input().split())
DIRS = [(0, -1), (0, 1), (1, 0), (-1, 0)]
g = [input() for _ in range(h)]
s = [*((r, -1) for r in range(h)), *((r, w) for r in range(h)), *((-1, c) for c in range(w)), *((h, c) for c in range(w))]
seen = [[False]*w for _ in range(h)]
t = 0
while s:
    r, c = s.pop()
    for dr, dc in DIRS:
        r2 = r + dr
        c2 = c + dc
        if r2 < 0 or r2 >= h or c2 < 0 or c2 >= w: continue
        if g[r2][c2] == '1': t += 1
        elif not seen[r2][c2]:
            seen[r2][c2] = True
            s.append((r2, c2))
print(t)
