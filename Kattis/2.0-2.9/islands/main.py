for _ in range(int(input())):
    c, *a = map(int, input().split())
    t = 0
    for i in range(1, 11):
        p = a[i-1]
        mn = a[i]
        for j in range(i, 12):
            if a[j] <= p: break
            mn = min(mn, a[j])
            t += mn > a[j+1]
    print(c, t)
