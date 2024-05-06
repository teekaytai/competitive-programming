DIRS = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
h, w = map(int, input().split())
g = [input() for _ in range(h)]
t = 0
x = 0
for r in range(h):
    for c in range(w):
        v = sum(g[r+dr][c+dc]=='o' for dr, dc in DIRS if 0<=r+dr<h and 0<=c+dc<w)
        if g[r][c] == 'o': t += v
        else: x = max(x, v)
print(t//2 + x)
