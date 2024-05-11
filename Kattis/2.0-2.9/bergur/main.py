input()
*a, = map(int, input().split())
t = 0
m = a[-1]
for x in reversed(a):
    m = min(m, x)
    t += m
print(t)
