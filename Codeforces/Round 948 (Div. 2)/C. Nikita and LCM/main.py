from math import lcm
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, l = sorted(map(int, input().split()))
    if any(l%x for x in a): print(n); return
    s = {l, *a}
    ps = []
    pc = []
    p = 2
    while p*p <= l:
        if l % p == 0:
            ps.append(p)
            pc.append(0)
            while l % p == 0:
                l //= p
                pc[-1] += 1
        p += 1
    if l > 1: ps.append(l); pc.append(1)
    def f(i):
        if i == len(ps): yield 1; return
        for v in f(i+1):
            for j in range(pc[i]+1):
                yield v * ps[i]**j
    m = 0
    for t in f(0):
        q = []
        for x in a:
            if t % x == 0:
                q.append(x)
        if lcm(*q) not in s:
            m = max(m, len(q))
    print(m)

tcs = int(input())
for tc in range(tcs):
    main()
