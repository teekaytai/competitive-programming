from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 1000000007
N = 200002
*fac, = accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1)

def main():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)
    if n == 2:
        print(2)
        return
    seen = [False] * n
    seen[0] = True
    st = [(0, -1)]
    while st:
        u, p = st.pop()
        for v in g[u]:
            if v == p: continue
            if seen[v]:
                print(0)
                return
            seen[v] = True
            st.append((v, u))
    a = [sum(len(g[v]) > 1 for v in vs) for vs in g]
    if any(s > 2 for s in a):
        print(0)
        return
    x = 2
    b = 0
    for u, s in enumerate(a):
        d = len(g[u])
        if d == 1: continue
        b += 1
        x = x * fac[d - s] % MOD
    print(x if b < 2 else x * 2 % MOD)

tcs = int(input())
for tc in range(tcs):
    main()
