for _ in range(int(input())):
    _, *a = map(int, input().split())
    a.extend(a[:2])
    t = 0
    for i in range(0, len(a)-2, 2):
        t += a[i]*a[i+3] - a[i+1]*a[i+2]
    print(t/2)
