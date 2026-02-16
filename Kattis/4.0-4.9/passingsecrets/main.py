from collections import defaultdict
from heapq import *

I = iter(open(0))
for l in I:
    ss, tt = l.split()
    ma = defaultdict(lambda: len(ma))
    n = int(next(I))
    g = []
    for _ in range(n):
        a = next(I).split()
        w = len(a) - 1
        for i, uu in enumerate(a):
            u = ma[uu]
            while len(g) <= u:
                g.append([])
            for j in range(i):
                v = ma[a[j]]
                g[u].append((v, w))
                g[v].append((u, w))
    V = len(ma)
    rma = [None] * V
    for x, v in ma.items():
        rma[v] = x
    if ss not in ma or tt not in ma:
        print('impossible')
        continue
    s = ma[ss]
    t = ma[tt]
    ps = [-1] * V
    pq = [(0, s)]
    ds = [float('inf')] * V
    ds[s] = 0
    while pq:
        d, u = heappop(pq)
        if ds[u] != d: continue
        if u == t:
            c = t
            a = [rma[c]]
            while c != s:
                c = ps[c]
                a.append(rma[c])
            print(d - 1 + (s == t), *reversed(a))
            break
        for v, w in g[u]:
            d2 = d + w
            if d2 < ds[v]:
                ds[v] = d2
                ps[v] = u
                heappush(pq, (d2, v))
    else:
        print('impossible')
