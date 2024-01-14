from functools import reduce
from math import gcd
import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n = int(input())
    *a, = map(int, input().split())
    t = 1
    for i in range(1, n):
        if n%i>0:continue
        t += reduce(gcd, (abs(a[j] - a[j + i]) for j in range(n-i))) != 1
    print(t)
