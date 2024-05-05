n = int(input())
g = [[*map(int, input().split())] for _ in range(n)]
mn = 0, 0, 0, 0, -1, -1, -1
for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            a, b, c = sorted((g[i][j], g[j][k], g[k][i]))
            mn = min(mn, (-a*b*c, a, b, c, i+1, j+1, k+1))
print(*mn[-3:])
