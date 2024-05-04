from itertools import chain
g = [input() for _ in range(8)]
def d1(i):
    l = []
    if i < 8:
        j = i
        i = 0
    else:
        i -= 7
        j = 7
    while i < 8 and j >= 0:
        l.append(g[i][j])
        i += 1; j -= 1
    return l
def d2(i):
    l = []
    if i < 8:
        j = i
        i = 7
    else:
        i = 16 - i - 1
        j = 7
    while i >= 0 and j >= 0:
        l.append(g[i][j])
        i -= 1; j -= 1
    return l
print(['invalid', 'valid'][sum(l.count('*') for l in g) == 8 and all(l.count('*')<=1 for l in chain(g, zip(*g), [d1(i) for i in range(15)], [d2(i) for i in range(15)]))])
