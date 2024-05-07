DIRS = [(-1, -2), (-2, -1), (-2, 1), (-1, 2)]
g = [input() for _ in range(5)]
s = 0
for r in range(5):
    for c in range(5):
        if g[r][c] != 'k': continue
        s += 1
        if any(g[r+dr][c+dc] == 'k' for dr, dc in DIRS if 0<=r+dr<5 and 0<=c+dc<5): print('invalid'); exit()
print('in'*(s!=9) + 'valid')
