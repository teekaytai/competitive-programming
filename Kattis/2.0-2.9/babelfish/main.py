a, b = open(0).read().split('\n\n')
d = {}
for l in a.split('\n'):
    v, k = l.split()
    d[k] = v
for l in b.split():
    print(d.get(l, 'eh'))
