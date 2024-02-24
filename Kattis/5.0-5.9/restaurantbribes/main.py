n, m, k = map(int, input().split())
g = [[] for _ in range(n)]
C = {}
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1; v -= 1
    g[u].append(v)
    g[v].append(u)
for _ in range(k):
    v, c = map(int, input().split())
    v -= 1
    C[v] = c
d = [sum(u in C for u in g[v]) for v in range(n)]
t = 0
for v, c in C.items():
    e = sum(100 / d[u] if u not in C else 0 for u in g[v])
    mx = 0
    for i in range(1, 11):
        x = e * i - (i * c) ** 2
        if x < mx: break
        mx = x
    t += mx
print(t)
