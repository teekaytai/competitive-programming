from itertools import combinations
n = int(input())
g = [[int(x) for x in input().split()] for _ in range(n)]
print(sum(g[i][j]&g[j][k]&g[k][i] for i, j, k in combinations(range(n), 3)))
