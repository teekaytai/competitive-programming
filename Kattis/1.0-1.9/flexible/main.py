n, m = map(int, input().split())
a = [0, *map(int, input().split()), n]
s = {a[i] - a[j] for i in range(m+2) for j in range(i)}
print(*sorted(s))
