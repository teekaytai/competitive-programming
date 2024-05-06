from collections import Counter
from itertools import accumulate

tcs = int(input())
for _ in range(tcs):
    input()
    n = int(input())
    *a, = map(int, input().split())
    *p, = accumulate(a)
    c = Counter()
    t = 0
    for i in range(n-1, -1, -1):
        c[p[i]] += 1
        t += c[47 - a[i] + p[i]]
    print(t)
