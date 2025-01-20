import re
m = [[0,1,2], [3,4,5], [6,7,8], [9,10,11], [12,13,14], [15,16,17], [18,19,20], [21,22,23],
     [0,9,21], [3,10,18], [6,11,15], [1,4,7], [16,19,22], [8,12,17], [5,13,20], [2,14,23]]
g = [[] for _ in range(24)]
d = [[] for _ in range(24)]
for i, r in enumerate(m):
    for j, v in enumerate(r):
        if j > 0: g[v].append(r[j-1])
        if j < 2: g[v].append(r[j+1])
        d[v].append(i)
a = re.findall(r'[WB\.]', open(0).read())
a.pop(12)
def f(r):
    return sum(a[v]=='W' for v in r) == 3
def main():
    for u in range(24):
        if all(not f(m[i]) for i in d[u]): continue
        for v in g[u]:
            if a[v] != '.': continue
            a[u], a[v] = a[v], a[u]
            if any(f(m[i]) for i in d[v]):
                return True
            a[u], a[v] = a[v], a[u]
    return False
print('no ' * (not main()) + 'double mill')
