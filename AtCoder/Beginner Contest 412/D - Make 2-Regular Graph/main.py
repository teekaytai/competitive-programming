from itertools import permutations
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    g = [[0] * n for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        g[u][v] = 1
        g[v][u] = 1
    mn = 1000000
    for p in permutations(range(n)):
        if any(p[p[i]] == i for i in range(n)): continue
        mn = min(mn, sum(g[i][j] ^ (p[i] == j or p[j] == i) for i in range(n) for j in range(i)))
    print(mn)

main()
