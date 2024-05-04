from collections import Counter
*a, = map(str.split, open(0))
a.sort(key=lambda p: p[::-1])
c = Counter(p[0] for p in a)
for x, y in a:
    if c[x] > 1: print(x, y)
    else: print(x)
