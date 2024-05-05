n, m = map(int, input().split())
a = [f'T{i}' for i in range(1, n+1)]
for _ in range(m):
    x, y = input().split()
    i = a.index(x)
    j = a.index(y)
    if j < i:
        a.insert(i, a.pop(j))
print(*a)
