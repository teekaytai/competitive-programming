input()
*a, = map(int, input().split())
_, *b = map(int, input().split())
s = 0
m = a[0]
t = 0
for x, y in zip(a, b):
    s += x
    t += 1
    m = min(m, x)
    d = (max(y-t, 0)+1)//2*2
    s += m * d
    t += d
print(s)
