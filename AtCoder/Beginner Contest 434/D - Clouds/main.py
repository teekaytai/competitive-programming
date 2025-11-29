import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    g = [[0] * 2001 for _ in range(2001)]
    a = []
    for _ in range(n):
        u, d, l, r = map(int, input().split())
        u -= 1
        d -= 1
        l -= 1
        r -= 1
        a.append((u, d, l, r))
        g[u][l] += 1
        g[u][r + 1] -= 1
        g[d + 1][l] -= 1
        g[d + 1][r + 1] += 1
    cs = [[0] * 2001 for _ in range(2001)]
    T = -2001-2000
    for i, row in enumerate(g):
        for j in range(len(row)):
            if i > 0:
                row[j] += g[i - 1][j]
            if j > 0:
                row[j] += row[j - 1]
            if i > 0 and j > 0:
                row[j] -= g[i - 1][j - 1]
            cs[i][j] = row[j] == 1
            T += row[j] == 0
            if i > 0:
                cs[i][j] += cs[i - 1][j]
            if j > 0:
                cs[i][j] += cs[i][j - 1]
            if i > 0 and j > 0:
                cs[i][j] -= cs[i - 1][j - 1]
    for u, d, l, r in a:
        t = cs[d][r]
        if l > 0: t -= cs[d][l - 1]
        if u > 0: t -= cs[u - 1][r]
        if l > 0 and u > 0: t += cs[u - 1][l - 1]
        print(T + t)

main()
