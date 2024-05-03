from functools import reduce
from math import gcd
n, m = map(int, input().split())
*a, = map(int, input().split())
a.append(360)
g = reduce(gcd, a)
for x in map(int, input().split()):
    print(['YES', 'NO'][(x-a[0])%g!=0])
