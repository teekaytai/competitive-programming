n, m = map(int, input().split())
a = [int(input()) for _ in range(n)]
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
seen = [False] * n
for i in range(n):
    if seen[i]: continue
    s = [i]
    t = a[i]
    seen[i] = True
    while s:
        u = s.pop()
        for v in g[u]:
            if seen[v]: continue
            seen[v] = True
            s.append(v)
            t += a[v]
    if t != 0: print('IMPOSSIBLE'); break
else:
    print('POSSIBLE')
