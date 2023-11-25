n = int(input())
a = [int(x) for x in input().split()]
m = 0
l = [0] * n
r = [0] * n
for i in range(n - 1, -1, -1):
    l[i] = a[i] + i
    if i < n - 1:
        l[i] = max(l[i], l[i + 1])
for i, x in enumerate(a):
    r[i] = x + n - i - 1
    if i > 0:
        r[i] = max(r[i], r[i - 1])
print(min(max((r[i - 1] if i > 0 else 0), a[i], (l[i + 1] if i < n - 1 else 0)) for i in range(n)))
