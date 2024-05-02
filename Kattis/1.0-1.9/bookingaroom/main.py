n, m = map(int, input().split())
a = list(range(1, n+1))
for _ in range(m):
    a[int(input())-1] = 0
print(next((i for i in a if i), 'too late'))
