from collections import defaultdict
d = defaultdict(int)
*a, _ = open(0)
x = 0
y = 0
for l in a:
    t, p, c = l.split()
    if c == 'right':
        x += 1
        y += int(t) + d[p]
    else:
        d[p] += 20
print(x, y)
