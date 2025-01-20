d, n, *a = map(float, open(0).read().split())
l = 0.
r = min(1., d)
t = 0.
for i, x in enumerate(a, 1):
    t += x
    l = max(l, i*d - t)
    r = min(r, i*d - (t-1))
    if l >= r: print('impossible'); break
else:
    print('possible')
