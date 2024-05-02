from operator import itemgetter
_, *a, = [(*map(int, l.split()),) for l in open(0)]
a.sort(key=itemgetter(1))
c = 0
t = 0
for s, f in a:
    if s >= c:
        c = f
        t += 1
print(t)
