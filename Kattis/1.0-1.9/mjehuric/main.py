*a, = map(int, input().split())
i = 0
c = 0
while c < 4:
    j = i%4
    k = i%4+1
    if a[j] > a[k]:
        a[j], a[k] = a[k], a[j]
        print(*a)
        c = 0
    else:
        c += 1
    i += 1
