v, *a, _ = open(0)
v = v.strip()
d = {}
for l in a:
    r, *c = l.split()
    for x in c:
        d[x] = r
a = [v]
while v in d:
    v = d[v]
    a.append(v)
print(*a)
