from collections import Counter
_, *a = open(0)
c = Counter(a)
m = min(c.values())
for k, v in sorted(c.items()):
    if v == m: print(k, end='')
