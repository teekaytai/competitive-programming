from collections import defaultdict
from itertools import combinations

ans = {}
for w in open(0).read().split():
    h = 0
    for c in w.lower():
        if not c.isalpha(): continue
        h = (h << 5) + ord(c) - 96
    if h != 0:
        ans[h] = []

d = defaultdict(list)

for k, vs in ans.items():
    ma = 31
    p = 0
    while k & ma:
        d[k & ~ma].append(k)
        k2 = k & p
        p |= ma
        if ma == 31 or (k & ma) >> 5 != k & (ma >> 5):
            k2 |= (k & ~p) >> 5
            vs2 = ans.get(k2)
            if vs2 is not None:
                vs.append(k2)
                vs2.append(k)
        if ma > 31:
            ma2 = ma >> 5
            k3 = k & ~(ma | ma2)
            k3 |= (k & ma2) << 5
            k3 |= (k & ma) >> 5
            if k3 != k and k3 in ans:
                vs.append(k3)
        ma <<= 5

for vs in d.values():
    for v1, v2 in combinations(vs, 2):
        ans[v1].append(v2)
        ans[v2].append(v1)

def f(h):
    a = []
    while h:
        bs = h & 31
        a.append(chr(96 + bs))
        h >>= 5
    return ''.join(reversed(a))

res = []
for k, vs in ans.items():
    if vs:
        res.append(f'{f(k)}: {" ".join(sorted(f(v) for v in vs))}')
res.sort()
print(*res or ['***'], sep='\n')
