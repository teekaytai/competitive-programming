n, m = map(int, input().split())
n *= 60
t = 0
for x in sorted(map(int, input().split())):
    if t + x > n: break
    t += x
print(t)
