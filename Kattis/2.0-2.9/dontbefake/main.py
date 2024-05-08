c = [0] * 86400
for _ in range(int(input())):
    _, *a = map(int, input().split())
    for x, y in zip(a[::2], a[1::2]):
        for i in range(x,y+1): c[i] += 1
print(m := max(c))
print(c.count(m))
