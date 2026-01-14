R = list(zip([900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1], 'CM D CD C XC L XL X IX V IV I'.split()))
l = []
r = []
for i in range(1000):
    s = ''
    v = i
    for x, c in R:
        while v >= x:
            v -= x
            s += c
    (l if s < 'M' else r).append((s, i))
l.sort()
r.sort(reverse=True)
lm = {x: i for i, (_, x) in enumerate(l)}
rm = {x: i for i, (_, x) in enumerate(r, start=1)}
n, *a = map(int, open(0))
for x in a:
    q, x = divmod(x, 1000)
    if x in lm:
        print(q * len(lm) + lm[x])
    else:
        print(-q * len(rm) - rm[x])
