import sys

sys.setrecursionlimit(10000)

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    g = [[*map(int, input().split())] for _ in range(3)]
    N = 2*n+1
    G = [[] for _ in range(N)]
    Gr = [[] for _ in range(N)]
    for a,b,c in zip(*g):
        G[-a].append(b); Gr[b].append(-a)
        G[-a].append(c); Gr[c].append(-a)
        G[-b].append(a); Gr[a].append(-b)
        G[-b].append(c); Gr[c].append(-b)
        G[-c].append(a); Gr[a].append(-c)
        G[-c].append(b); Gr[b].append(-c)

    used = [False] * N
    order = []

    def dfs(u):
        used[u] = True
        for v in G[u]:
            if not used[v]: dfs(v)
        order.append(u)

    for i in range(-n, n+1):
        if not used[i]: dfs(i)
    used = [False] * N
    for i in reversed(order):
        if not used[i]:
            s = [i]
            used[i] = True
            comp = set()
            while s:
                u = s.pop()
                if abs(u) in comp: print('NO'); return
                comp.add(abs(u))
                for v in Gr[u]:
                    if not used[v]:
                        used[v] = True
                        s.append(v)
    print('YES')

tcs = int(input())
for tc in range(tcs):
    main()
