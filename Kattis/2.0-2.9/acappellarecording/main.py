n, d = map(int, input().split())
a = sorted(int(input()) for _ in range(n))
c = -2e9
t = 0
for x in a:
    if x - c > d:
        c = x
        t += 1
print(t)
