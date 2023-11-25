t = int(input())
for I in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    print(a[-1] - a[n] + a[n - 1] - a[0])
    for i in range(n):
        print(a[i], a[n + i])
