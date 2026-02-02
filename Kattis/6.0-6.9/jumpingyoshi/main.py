n, *a = map(int, open(0).read().split())
pars = list(range(n))
def find(i):
    r = i
    while pars[r] != r:
        r = pars[r]
    k = i
    while k != r:
        pars[k], k = r, pars[k]
    return r
def union(i, j):
    r1 = find(i)
    r2 = find(j)
    if r1 != r2:
        pars[r1] = r2
g = [[] for _ in range(n)]
for i, x in enumerate(a):
    if i - x >= 0:
        vs = g[i - x]
        for v in vs:
            union(i, v)
        vs[1:] = []
    if i + x < n:
        g[i + x].append(i)
r0 = find(0)
print(next(i for i in range(n - 1, -1, -1) if find(i) == r0))
