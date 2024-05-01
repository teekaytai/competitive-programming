DIRS = [(-1, 0), (1, 0), (0, 1), (0, -1)]
h, w = map(int, input().split())
g = [list(input()) for _ in range(h)]
t = 0
for R in range(h):
    for C in range(w):
        if g[R][C] != 'L': continue
        t += 1
        s = [(R, C)]
        g[R][C] = 'W'
        while s:
            r, c = s.pop()
            for dr, dc in DIRS:
                r2 = r + dr
                c2 = c + dc
                if 0<=r2<h and 0<=c2<w and g[r2][c2]!='W':
                    g[r2][c2] = 'W'
                    s.append((r2, c2))
print(t)
