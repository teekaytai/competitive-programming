def f(p, q):
    if p == q: return 1
    if p < q: return 2 * f(p, q-p)
    return 2 * f(p-q, q) + 1

_, *a = open(0)
for l in a:
    i, frac = l.split()
    print(i, f(*map(int,frac.split('/'))))
