from functools import reduce
from math import gcd
tcs = int(input())
for tc in range(tcs):
    n, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    c = a.count(k)
    if c == n:
        print(0)
        continue
    if c > 0:
        print(-1)
        continue
    gr = any(x > k for x in a)
    le = any(x < k for x in a)
    if gr and le:
        print(-1)
        continue
    d = [x-k for x in a]
    g = reduce(gcd, d)
    print(sum(abs(x//g)-1 for x in d))
