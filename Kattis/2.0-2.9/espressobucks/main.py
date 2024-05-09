DIRS = [(-1, 0), (1, 0), (0, 1), (0, -1)]
h, w = map(int, input().split())
g = [list(input()) for _ in range(h)]
for r in range(h):
    for c in range(w):
        if g[r][c] == '.' and all(g[r+dr][c+dc]!='E' for dr, dc in DIRS if 0<=r+dr<h and 0<=c+dc<w):
            g[r][c] = 'E'
for row in g:
    print(''.join(row))
