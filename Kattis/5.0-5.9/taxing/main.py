from bisect import *
n = int(input())
a = [0.0]
b = [0.0]
ps = []
t = 0.0
for _ in range(n):
    s, p = map(float, input().split())
    p = (100 - p) / 100
    a.append(a[-1] + s)
    b.append(b[-1] + s * p)
    ps.append(p)
ps.append((100 - float(input())) / 100)
for _ in range(int(input())):
    e, m = map(float, input().split())
    i = bisect_right(a, e) - 1
    x = m + b[i] + (e - a[i]) * ps[i]
    j = bisect_right(b, x) - 1
    print((x - b[j]) / ps[j] + a[j] - e)
