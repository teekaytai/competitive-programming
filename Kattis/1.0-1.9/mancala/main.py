for _ in range(int(input())):
    k, n = map(int, input().split())
    a = [0] * 80
    mx = 0
    for i in range(n):
        j = 0
        while a[j]:
            a[j] -= 1
            j += 1
        a[j] = j + 1
        mx = max(mx, j)
    print(k, mx+1)
    for i in range(0, mx+1, 10):
        print(*a[i:min(i+10, mx+1)])
