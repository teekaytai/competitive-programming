s = 0
v = 0
for l in open(0):
    t, *a = l.split()
    a = list(map(int, a))
    if t == 'buy':
        s += a[0]
        v += a[0] * a[1]
    elif t == 'sell':
        v *= (s - a[0]) / s
        s -= a[0]
    elif t == 'split':
        s *= a[0]
    elif t == 'merge':
        if s:
            v *= (s - s % a[0]) / s
            s //= a[0]
    else:
        print((a[0] - max((a[0] - v / s) * 0.3, 0)) * s if s else 0)
