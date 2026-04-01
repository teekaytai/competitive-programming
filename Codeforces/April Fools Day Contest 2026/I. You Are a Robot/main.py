import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    if n == 1:
        print(1)
        return
    ps = [int(x) - 1 for x in input().split()]
    g = [[] for _ in range(n)]
    for i, p in enumerate(ps):
        g[p].append(i)
    a = [int(x) for x in input().split()]
    dp = [(-1,-1,-1)] * n
    for i in range(n - 1, -1, -1):
        if not g[i]:
            dp[i] = 0, 0, i+1
            continue
        mn = 1000000000, 0, -1
        for v in g[i]:
            x, y, z = dp[v+1]
            x += a[v] == 1
            y += a[v] == 2
            mn = min(mn, (x, y, z))
        dp[i] = mn
    print(dp[0][2])

tcs = int(input())
for tc in range(tcs):
    main()
