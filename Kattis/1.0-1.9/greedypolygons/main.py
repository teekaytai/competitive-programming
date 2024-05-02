import math
for _ in range(int(input())):
    n, l, d, g = map(int, input().split())
    print(l*n*l/4/math.tan(math.pi/n) + n*g*d*l + math.pi*(d*g)**2)
