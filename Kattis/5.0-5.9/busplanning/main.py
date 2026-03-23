import sys

input = lambda: sys.stdin.readline().rstrip()

def main():
    n, m, k = [int(x) for x in input().split()]
    ss = []
    ma = {}
    for i in range(n):
        s = input()
        ss.append(s)
        ma[s] = i
    g = [[] for _ in range(n)]
    for _ in range(m):
        su, sv = input().split()
        u = ma[su]
        v = ma[sv]
        g[u].append(v)
        g[v].append(u)
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

    best = n
    ans = list(range(n))
    cs = [-1] * n
    xs = [k] * n

    def f(s=0, c=0):
        nonlocal best, ans
        if s == n:
            if c < best:
                best = c
                ans = cs[:]
            return
        u = o[s]
        can = [True] * (c + 1)
        for v in g[u]:
            if cs[v] != -1:
                can[cs[v]] = False
        for i in range(min(c + 1, best - 1)):
            if i + 1 >= best: break
            if not can[i] or not xs[i]: continue
            cs[u] = i
            xs[i] -= 1
            f(s + 1, max(c, i + 1))
            xs[i] += 1
            if c >= best: break
        cs[u] = -1

    f()
    print(best)
    for i in range(best):
        print(*(ss[j] for j, x in enumerate(ans) if x == i))

main()
