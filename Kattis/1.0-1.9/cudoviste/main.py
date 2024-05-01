h, w = map(int, input().split())
g = [input() for _ in range(h)]
c = [0] * 5
for i in range(h-1):
    for j in range(w-1):
        p = g[i][j:j+2] + g[i+1][j:j+2]
        if '#' in p: continue
        c[p.count('X')] += 1
print(*c, sep='\n')
