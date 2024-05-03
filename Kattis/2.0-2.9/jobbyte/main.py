n = int(input())
*a, = map(int, input().split())
p = [0]*n
for i, x in enumerate(a):
    p[x-1] = i
t = 0
for i, x in enumerate(a):
    if x == i+1: continue
    t += 1
    j = p[i]
    a[i], a[j] = a[j], a[i]
    p[i] = i
    p[x-1] = j
print(t)
