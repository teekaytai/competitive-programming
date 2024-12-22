import bisect
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n,m = map(int, input().split())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    v = a[0]
    a.sort()
    I = a.index(v)
    c = []
    for x in b:
        i = bisect.bisect_left(a, x)
        c.append(0 if i <= I else n - i)
    c.sort()
    ans = []
    for k in range(1, m+1):
        t = 0
        for i in range(k-1, m, k):
            t += c[i] + 1
        ans.append(t)
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
