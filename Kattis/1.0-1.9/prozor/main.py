h, w, k = map(int, input().split())
g = [list(input()) for _ in range(h)]
R, C = -1, -1
mx = 0
for r in range(1, h-k+2):
    for c in range(1, w-k+2):
        s = sum(x == '*' for row in g[r:r+k-2] for x in row[c:c+k-2])
        if s > mx:
            mx = s
            R, C = r, c
R -= 1
C -= 1
Y, X = R+k-1, C+k-1
g[R][C] = '+'
g[R][X] = '+'
g[Y][C] = '+'
g[Y][X] = '+'
for r in R, Y:
    for c in range(C+1, X): g[r][c] = '-'
for c in C, X:
    for r in range(R+1, Y): g[r][c] = '|'
print(mx)
for row in g: print(''.join(row))
