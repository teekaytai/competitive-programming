from collections import defaultdict
_, *a, = open(0)
a = a[::-1]
s = [(0, [*range(len(a[0]))])]
mx = 0
while s:
    d, r = s.pop()
    mx = max(mx, d)
    D = defaultdict(list)
    for x in r:
        D[a[d][x]].append(x)
    for k, v in D.items():
        if len(v) > 1:
            s.append((d+1, v))
print(len(a) - mx - 1)
