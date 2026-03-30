from math import gcd
n, *a = map(int, open(0).read().split())
s = set()
p = []
for i in range(n - 1, -1, -1):
    p2 = [a[i]]
    g = a[i]
    s.add(g)
    for x in p:
        g2 = gcd(g, x)
        if g2 != g:
            s.add(g2)
            g = g2
            p2.append(x)
    p = p2
print(len(s))
