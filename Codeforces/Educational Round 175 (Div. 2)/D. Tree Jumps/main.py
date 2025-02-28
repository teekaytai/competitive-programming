from collections import deque
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)
MOD = 998244353
def main():
    n = int(input())
    *ps, = map(int, input().split())
    g = [[] for _ in range(n)]
    for v, p in enumerate(ps):
        p -= 1
        g[p].append(v + 1)
    dp = [0] * n
    q = deque(g[0])
    seen = [False] * n
    seen[0] = True
    s = 1
    t = 1
    while q:
        s2 = 0
        for _ in range(len(q)):
            u = q.popleft()
            seen[u] = True
            dp[u] = (dp[u] + s) % MOD
            t = (t + dp[u]) % MOD
            s2 = (s2 + dp[u]) % MOD
            for v in g[u]:
                if seen[v]: continue
                dp[v] = -dp[u]
                q.append(v)
        s = s2
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
