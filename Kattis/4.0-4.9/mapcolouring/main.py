def main():
    n, m = [int(x) for x in input().split()]
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = [int(x) for x in input().split()]
        g[u].append(v)
        g[v].append(u)
    cs = [-1] * n
    o = []
    seen = [False] * n
    qi = 0
    for i in range(n):
        if seen[i]: continue
        seen[i] = True
        o.append(i)
        while qi < len(o):
            u = o[qi]
            for v in g[u]:
                if seen[v]: continue
                seen[v] = True
                o.append(v)
            qi += 1

    def f(s=0, c=-1, mn=5):
        if s == n:
            return c + 1
        u = o[s]
        can = [True] * 4
        for v in g[u]:
            if cs[v] != -1:
                can[cs[v]] = False
        for i in range(min(c + 2, 4)):
            if not can[i]: continue
            if i >= mn - 1: break
            cs[u] = i
            mn = min(mn, f(s + 1, max(c, i), mn))
            if c >= mn - 1: break
        cs[u] = -1
        return mn

    ans = f()
    print(ans if ans < 5 else 'many')

tcs = int(input())
for tc in range(tcs):
    main()
