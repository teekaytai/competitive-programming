l, h, k = map(int, input().split())
g = [['_']*l for _ in range(h)]
for d in range(k):
    a, b, c, r = map(int, input().split())
    for i in range(r, min(r+b, h)):
        for j in range(c, min(c+a, l)):
            g[i][j] = chr(97+d)
for row in g:
    print(''.join(row))
