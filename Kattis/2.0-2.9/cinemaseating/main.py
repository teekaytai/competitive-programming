h, w = map(int, input().split())
g = [[0] * (w+1) for _ in range(h+1)]
for _ in range(int(input())):
    r, c = map(int, input().split())
    g[r-1][c-1] = 1
res = [0] * 9
for r in range(h):
    for c in range(w):
        if g[r][c]: res[sum(g[i][j] for i in range(r-1, r+2) for j in range(c-1, c+2)) - 1] += 1
print(*res)
