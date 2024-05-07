n, m = map(int, input().split())
t = 0
c = m
for _ in range(n):
    x = input()
    d = int(x[0]) + len(x) - 1
    if d > c: c = m; t += 1
    c -= d
print(t)
