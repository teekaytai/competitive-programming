for _ in range(int(input())):
    n, *a = map(int, input().split())
    print(next(i+1 for i in range(1, n) if a[i] != a[i-1] + 1))
