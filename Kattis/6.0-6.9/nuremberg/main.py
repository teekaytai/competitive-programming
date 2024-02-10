import sys
sys.setrecursionlimit(50001)

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n = int(input())
    g = [[] for _ in range(n)]
    for _ in range(n-1):
        u, v, w = map(int, input().split())
        u -= 1; v -= 1
        g[u].append((v, w))
        g[v].append((u, w))
    F = [0] * n
    m = int(input())
    for _ in range(m):
        a, f = map(int, input().split())
        F[a-1] = f
    T = [0] * n
    def dfs(v, p):
        t = F[v]
        c = 0
        for u, w in g[v]:
            if u == p: continue
            dt, dc = dfs(u, v)
            t += dt
            c += dc + w * dt
        T[v] = t
        return t, c
    best = dfs(0, 0)[1]
    best_vs = [1]
    s = [(0, 0, best)]
    while s:
        v, p, c = s.pop()
        for u, w in g[v]:
            if u == p: continue
            c2 = c + w * (T[0] - 2 * T[u])
            if c2 < best:
                best = c2
                best_vs = [u+1]
            elif c2 == best:
                best_vs.append(u+1)
            s.append((u, v, c2))
    print(2*best)
    print(*sorted(best_vs))
