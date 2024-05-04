import math
p, a, b, c, d, n = map(int, input().split())
f = lambda k: p*(math.sin(a*k+b)+math.cos(c*k+d)+2)
x = f(1)
mx = 0.
for i in range(2, n+1):
    y = f(i)
    mx = max(mx, x - y)
    x = max(x, y)
print(mx)
