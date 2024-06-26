from itertools import accumulate
from math import gcd
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, m, k = map(int, input().split())
    H = [list(map(int, input().split())) for _ in range(n)]
    g = [[[-1, 1][b] for b in map(int, input())] for _ in range(n)]
    d = 0
    for i in range(n):
        for j in range(m):
            d += g[i][j] * H[i][j]
    p = [[0]*(m+1)]+[[*accumulate(row, initial=0)] for row in g]
    # printerr(p)
    for i in range(1, n+1):
        for j in range(m-k+1):
            p[i][j] = p[i][j+k] - p[i][j]
    # printerr(p)
    for j in range(m-k+1):
        for i in range(1, n+1):
            p[i][j] += p[i-1][j]
    for j in range(m-k+1):
        for i in range(n-k+1):
            p[i][j] = p[i+k][j] - p[i][j]
    # printerr(p)
    a = [p[i][j] for i in range(n-k+1) for j in range(m-k+1) if p[i][j]]
    # printerr(a)
    print(['NO','YES'][a and d%gcd(*a)==0 or d==0])

tcs = int(input())
for tc in range(tcs):
    main()
