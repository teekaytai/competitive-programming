import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n,k,x = map(int, input().split())
    *a, = map(int, input().split())
    a.sort()
    a[-x:] = [-v for v in a[-x:]]
    lo = n-x-1
    t = c= sum(a)
    for i in range(min(k, n)):
        c -= a.pop()
        if lo >= 0:
            c -= a[lo] * 2
            a[lo] = -a[lo]
            lo -= 1
        t = max(t, c)
    print(t)
