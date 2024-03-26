n, m = map(int, input().split())
*a, = map(int, input())
t = 0
for i, x in enumerate(a):
    if x:
        t += 1
        if i < n-2:
            a[i+2] |= a[i+1]
            a[i+1] = 0
print(t)
