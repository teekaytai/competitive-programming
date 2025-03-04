n, m, *a = map(int, open(0).read().split())
pre = a[:n]
post = a[-n:]
g = [[] for _ in range(n + 1)]
s = []
seen = [False] * (n + 1)
i = 0
for u in pre:
    if s: g[s[-1]].append(u)
    s.append(u)
    seen[u] = True
    while i < n and seen[post[i]]:
        while s[-1] != post[i]: s.pop()
        s.pop()
        i += 1
for i in range(1, n + 1):
    print(f'{i}:', *g[i])
