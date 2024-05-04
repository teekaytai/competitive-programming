from bisect import bisect_left
n, m, *a = map(int, open(0).read().split())
p = a[:n]
p.sort()
t = 0
for x in a[n:]:
    t += p[bisect_left(p, x)] - x
print(t)
