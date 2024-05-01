h, w = map(int, input().split())
g = [list(map(int,input().split())) for _ in range(h)]
print(['Neibb','Jebb'][any(g[i][j] < min(g[i][j-1], g[i][j+1], g[i-1][j], g[i+1][j])for i in range(1, h-1) for j in range(1, w-1))])
