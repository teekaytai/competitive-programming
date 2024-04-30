_, *a = open(0)
b = sorted((s.split() for s in a), key=lambda c: int(c[1]))
d = {}
for v, _, k in b: d[k] = v
print(len(d))
print(*sorted(d.values()), sep='\n')
