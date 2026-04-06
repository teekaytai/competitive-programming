from collections import deque

def f(w):
    t = 0
    for c in w:
        t = t * 32 + ord(c) - 96
    return t

D, qs = open(0).read().split('\n\n')
rma = D.split()
ma = {f(w): i for i, w in enumerate(rma)}
g = [[] for _ in range(len(rma))]
for u, w in enumerate(rma):
    h = f(w)
    b = 1
    bm = 31
    for i in range(len(w)):
        h2 = h - (h & bm)
        for _ in range(26):
            h2 += b
            if h2 == h: continue
            v = ma.get(h2, None)
            if v is not None:
                g[u].append(v)
        b <<= 5
        bm <<= 5

for ws, wt in map(str.split, qs.splitlines()):
    s = ma[f(ws)]
    t = ma[f(wt)]
    ps = [-1] * len(g)
    ps[s] = s
    q = deque([s])
    while q:
        u = q.popleft()
        for v in g[u]:
            if ps[v] != -1: continue
            ps[v] = u
            if v == t:
                break
            q.append(v)
        else:
            continue
        break
    else:
        print('No solution.\n')
        continue
    ans = [wt]
    c = t
    b = False
    while ps[c] != c:
        c = ps[c]
        ans.append(rma[c])
    print('\n'.join(reversed(ans)), end='\n\n')
