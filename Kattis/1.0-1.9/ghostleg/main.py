n, m = map(int, input().split())
*a, = range(1, n+1)
for _ in range(m):
    i = int(input())
    a[i], a[i-1] = a[i-1], a[i]
print(*a, sep='\n')
