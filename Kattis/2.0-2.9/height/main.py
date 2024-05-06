for _ in range(int(input())):
    i, *a = map(int, input().split())
    t = 0
    for j in range(len(a)):
        while j and a[j] < a[j-1]:
            a[j], a[j-1] = a[j-1], a[j]
            t += 1
            j -= 1
    print(i, t)
