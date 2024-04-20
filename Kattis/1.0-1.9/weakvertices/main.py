while (n:=int(input())) > 0:
    g = [[*map(int,input().split())]for _ in range(n)]
    l = []
    for i in range(n):
        if not any(g[i][j] and any(g[j][k] and g[k][i] for k in range(n)) for j in range(n)):
            l.append(i)
    print(*l)
