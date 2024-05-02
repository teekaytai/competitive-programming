DIRS = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
h, w = map(int, input().split())
g = [list(input()) for _ in range(h)]
t = 0
for R, row in enumerate(g):
    for C, cell in enumerate(row):
        if cell == '.': continue
        t += 1
        cell = '.'
        s = [(R, C)]
        while s:
            r, c = s.pop()
            for dr, dc in DIRS:
                r2 = r + dr
                c2 = c + dc
                if 0<=r2<h and 0<=c2<w and g[r2][c2] == '#':
                    g[r2][c2] = '.'
                    s.append((r2, c2))
print(t)
