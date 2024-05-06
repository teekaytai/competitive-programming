n, m = map(int, input().split())
t = 0
for x in map(int, input().split()):
    if x > n: t += 1
    else: n -= x
print(t)
