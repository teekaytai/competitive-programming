from operator import itemgetter
n = int(input())
a = []
for _ in range(n):
    s, x, y = input().split()
    a.append((float(y), float(x), s))
a.sort()
m = min(a[3:], key=itemgetter(1))
mn = m[1] + sum(t[0] for t in a[:3])
best = [m] + a[:3]
for i in range(3):
    t = a[i][1] + sum(a[j][0] for j in range(4)) - a[i][0]
    if t < mn:
        mn = t
        best = [a[i]] + [t for t in a[:4] if t != a[i]]
print(mn)
for t in best:
    print(t[2])
