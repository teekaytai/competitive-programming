n, m = map(int, input().split())
if m < n-1 or m > 2*n-3: print(-1)
else:
    for i in range(2, n+1):
        print(1, i)
    for i in range(2, m-n+3):
        print(i, n)
