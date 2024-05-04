D = {'N': (-1, 0), 'S': (1, 0), 'W': (0, -1), 'E': (0, 1)}
h, w = map(int, input().split())
g = [input() for _ in range(h)]
seen = [[False] * w for _ in range(h)]
r, c = 0, 0
i = 0
while not seen[r][c]:
    seen[r][c] = True
    cell = g[r][c]
    if cell == 'T': print(i); break
    dr, dc = D[cell]
    r += dr
    c += dc
    if r < 0 or r >= h or c < 0 or c >= w: print('Out'); break
    i += 1
else:
    print('Lost')
