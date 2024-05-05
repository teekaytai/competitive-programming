n, k = map(int, input().split())
a = []
for _ in range(k):
    x, y = map(int, input().split())
    a.append((-y, x))
a.sort()
r = list(range(n))
for _, y in a:
    r[y], r[y+1] = r[y+1], r[y]
print(*r)
