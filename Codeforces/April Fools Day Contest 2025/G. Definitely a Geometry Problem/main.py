import math
n, k, *a = map(int, open(0).read().split())
p = sorted(zip(a[::2], a[1::2]))
print(math.pi * min(math.dist(p[i], p[i + k - 1]) for i in range(n - k + 1)) ** 2 / 4)
