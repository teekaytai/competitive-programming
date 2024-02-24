from functools import reduce
from math import gcd

tcs = int(input())
for tc in range(1, tcs+1):
    n, *a, = map(int, input().split())
    g = reduce(gcd, (abs(x-y) for x, y in zip(a, a[1:])))
    print(f'Case #{tc}:', (g - a[0]) % g)
