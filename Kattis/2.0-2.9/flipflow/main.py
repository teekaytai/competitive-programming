t, s, n = map(int, input().split())
*a, = map(int, input().split())
a.append(t)
c = 0
d = s
p = 0
for x in a:
    dt = x - p
    c = max(c-dt, 0)
    d = min(d+dt, s)
    c, d = d, c
    p = x
print(d)
