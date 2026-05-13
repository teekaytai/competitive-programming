import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

def main():
    n, m = [int(x) for x in input().split()]
    g = [[] for _ in range(n)]
    dp = [0] * n
    deg = [0] * n
    for _ in range(m):
        u, v = [int(x) for x in input().split()]
        u -= 1; v -= 1
        g[u].append(v)
        deg[v] += 1
    st = []
    dp[0] = 1
    for u, d in enumerate(deg):
        if d == 0:
            st.append(u)
    while st:
        u = st.pop()
        for v in g[u]:
            dp[v] = (dp[v] + dp[u]) % MOD
            deg[v] -= 1
            if deg[v] == 0:
                st.append(v)
    print(dp[-1])

tcs = int(input())
for tc in range(tcs):
    main()
