h, w = map(int, input().split())
g = [input() for _ in range(h)]
s = set()
for r, R in enumerate(g):
    c = R.find('x')
    if c == -1: continue
    if r == 0 or g[r-1][c] == '.':
        l = 1
        while r+l < h and c+l < w and g[r][c+l] == g[r+l][c] == 'x': l += 1
        s.add((r+1, c+1, l))
    c = R.rfind('x')
    if r == h-1 or g[r+1][c] == '.':
        l = 1
        while r-l >= 0 <= c-l and g[r][c-l] == g[r-l][c] == 'x': l += 1
        s.add((r-l+2, c-l+2, l))
for p in (2*[*s])[:2]:
    print(*p)
