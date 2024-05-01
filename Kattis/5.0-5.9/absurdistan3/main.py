import sys

input = lambda: sys.stdin.readline().strip()

n = int(input())
g = [set() for _ in range(n)]
done = [False] * n
for _ in range(n):
    u, v = map(int, input().split())
    u -= 1; v -= 1
    if v in g[u]:
        print(u + 1, v + 1)
        print(v + 1, u + 1)
        g[u].remove(v)
        g[v].remove(u)
        done[u] = True
        done[v] = True
    else:
        g[u].add(v)
        g[v].add(u)
def f(s):
    while s:
        u = s.pop()
        v, = g[u]
        print(u + 1, v + 1)
        done[u] = True
        g[v].remove(u)
        if len(g[v]) == 1 and not done[v]:
            s.append(v)
f([v for v, (adjs, b) in enumerate(zip(g, done)) if len(adjs) == 1 and not b])
for u, adjs in enumerate(g):
    if len(adjs) == 2:
        v = adjs.pop()
        g[v].remove(u)
        print(u + 1, v + 1)
        done[u] = True
        f([v])
