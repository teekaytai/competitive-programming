n, d = map(int, input().split())
*a, = map(int, input().split())
i = 0
t = 0
while a[i] > 0:
    t += a[i]
    a[i] = 0
    i = (i + d) % n
print(t)
