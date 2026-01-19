n, m = map(int, input().split())
g = [input() for _ in range(n)]
h = n // 2
a = []
l = 0
r = 0
while r < m:
    c = g[h][r]
    if c == '/':
        i = g[0].find(' ', r + 1)
        if i == -1: i = len(g[0])
        a += [g[h][l:r-1], '(', g[h][r+1:i],')**.5']
        l = r = i
    elif c == '=':
        i = g[h].find(' ', r)
        if i == -1: i = len(g[h])
        a += [g[h][l:r], '(', g[0][r:i], ')//(', g[2][r:i], ')']
        l = r = i
    r += 1
a += g[h][l:r]
print(round(eval(''.join(a))))
