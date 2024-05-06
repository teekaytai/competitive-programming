n, a, b = map(int, open(0))
c = []
i = 0
while n >= 0:
    if n % b == 0: c.append((i, n//b))
    n -= a
    i += 1
print(len(c))
for t in c: print(*t)
