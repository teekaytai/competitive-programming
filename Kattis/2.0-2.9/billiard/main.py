import math
*A, _ = open(0)
for l in A:
    a, b, s, m, n = map(int, l.split())
    x = m * a
    y = n * b
    print(f'{180/math.pi*math.atan(y/x):.2f}', f'{math.hypot(x, y) / s:.2f}')
