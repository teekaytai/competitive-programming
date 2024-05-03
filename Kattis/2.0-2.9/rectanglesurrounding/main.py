g = [[0]*501 for _ in range(500)]
while n:=int(input()):
    for _ in range(n):
        a,b,c,d = map(int, input().split())
        for x in range(a, c):
            g[x][b] += 1
            g[x][d] -= 1
    s = 0
    for x in range(500):
        t = 0
        for y, v in enumerate(g[x]):
            t += v
            s += t > 0
            g[x][y] = 0
    print(s)
