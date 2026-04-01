import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    INF = 1000000000
    ds = [[INF] * n for _ in range(n)]
    for i in range(n): ds[i][i] = 0
    for _ in range(m):
        u, v, w = [int(x) for x in input().split()]
        u -= 1; v -= 1
        ds[u][v] = min(ds[u][v], w)
        ds[v][u] = min(ds[v][u], w)
    for i in range(n):
        for k in range(n):
            for j in range(n):
                ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j])
    for i in range(1, n):
        print(-1 if ds[0][i] == INF else ds[0][i])

main()
