n, m = map(int, input().split())
*a, = map(int, input().split())
e = sum(1-v%2 for v in a[:m])
t = e > 1
for i in range(m, n):
    e += a[i-m]%2-a[i]%2
    t += e > 1
print(t)
