n, m = map(int, input().split())
a = list(range(-1, -n-1, -1))
for _ in range(m):
    u, v = map(int, input().split())
    a[u-1] += 1
    a[v-1] += 1
print(*a)
