a, b = 0, 0
for _ in range(int(input())):
    x, y = map(int, input().split())
    a += x
    b += y
r = b/a/60
if r <= 1:print('measurement error')
else:print(r)
