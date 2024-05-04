n, m = map(int, input().split())
*a, = map(int, input().split())
t = a[m]
x = 0
p = 0
a[m] = 301
a.sort()
i = 0
while t <= 300:
    x += 1
    p += t
    t += a[i]
    i += 1
print(x, p)
