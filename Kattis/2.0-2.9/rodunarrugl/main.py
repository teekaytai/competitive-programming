n = int(input())
*a, = map(int, input().split())
t = 0
for i, x in enumerate(a):
    if x == i+1: continue
    t += 2
    while x != i+1:
        a[x-1], x = x, a[x-1]
        t += 1
    a[i] = x
print(t)
