from functools import reduce
from math import gcd

tcs = int(input())
for tc in range(tcs):
    n = int(input())
    a = sorted(map(int, input().split()))
    if n == 1:
        print(1)
        continue
    g = reduce(gcd, [a[i + 1] - a[i] for i in range(n - 1)])
    t = sum((a[-1] - num) // g for num in a)
    p = 1
    while p < n and a[-1 - p] == a[-1] - g * p:
        p += 1
    print(t + p)
