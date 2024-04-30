import sys

input = lambda: sys.stdin.readline().strip()

n, m = map(int, input().split())
g = [[] for _ in range(n)]
ins = [0] * n
for _ in range(m):
    u, v = map(int, input().split())
    g[u-1].append(v-1)
    ins[v-1] += 1
s = [v for v in range(n) if not ins[v]]
ds = [1] * n
p = [-1] * n
mx = 0
mi = -1
while s:
    u = s.pop()
    if ds[u] > mx:
        mx = ds[u]
        mi = u
    for v in g[u]:
        d = ds[u] + 1
        if d > ds[v]:
            ds[v] = d
            p[v] = u
        ins[v] -= 1
        if not ins[v]: s.append(v)
a = []
v = mi
while v != -1:
    a.append(v+1)
    v = p[v]
print(mx)
print(*reversed(a))
