import bisect
from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = input()
    b = input()
    x = a[0] != b[0]
    t = n * n * x
    p = [0]
    q = [0]
    um = str(1 - int(b[0])) if x else b[0]
    for i in range(1, n):
        t += n * (n - i) * (a[i] != a[0])
        t += n * (n - i) * (b[i] != um)
        p.append(p[-1] + (1 if a[i] != a[0] else -1))
        q.append(q[-1] + (1 if b[i] != um else -1))
    q.sort()
    qps = list(accumulate(q, initial=0))
    s = sum(q)
    for v in p:
        if x:
            i = bisect.bisect_left(q, -v)
            t -= s - qps[i] + v * (n - i)
        else:
            i = bisect.bisect_left(q, -v + 2)
            t -= s - qps[i] + (v - 2) * (n - i)
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
