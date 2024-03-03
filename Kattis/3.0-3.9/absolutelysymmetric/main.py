import sys

input = lambda: sys.stdin.readline().strip()

n = int(input())
g = []
for _ in range(n):
    *a, = map(int, input().split())
    g.append(a)
res1 = [[0] * n for _ in range(n)]
res2 = [[0] * n for _ in range(n)]
can = True
same = True
for i in range(n):
    for j in range(i+1):
        if i == j:
            res1[i][j] = g[i][j]
            continue
        t = g[i][j] + g[j][i]
        if t % 2:
            can = False
            break
        b = abs(g[i][j]) == abs(g[j][i])
        if b:
            res1[i][j] = g[i][j]
            res1[j][i] = g[j][i]
        else:
            same = False
            m = t // 2
            res1[i][j] = m
            res1[j][i] = m
            res2[i][j] = g[i][j] - m
            res2[j][i] = g[j][i] - m
if not can:
    print(-1)
elif same:
    print(1)
    for row in res1:
        print(*row)
else:
    print(2)
    for row in res1:
        print(*row)
    for row in res2:
        print(*row)
