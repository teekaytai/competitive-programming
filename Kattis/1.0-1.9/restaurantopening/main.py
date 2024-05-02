h, w = map(int, input().split())
g = [list(map(int, input().split())) for _ in range(h)]
print(min(sum(g[i][j]*(abs(r-i)+abs(c-j))for i in range(h) for j in range(w)) for r in range(h) for c in range(w)))
