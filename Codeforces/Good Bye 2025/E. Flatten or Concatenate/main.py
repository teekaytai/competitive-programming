import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def q(l, r):
    print('?', l + 1, r + 1, flush=True)
    x = int(input())
    assert x != -1
    return x

def a(x):
    print('!', x, flush=True)

def main():
    n = int(input())
    assert n != -1
    l = 0
    r = n - 1
    s = q(l, r)
    while l < r:
        hs = s // 2
        lo = l + 1
        hi = r
        while lo < hi:
            mid = (lo + hi) // 2
            x = q(mid, r)
            if x == hs:
                lo = mid
                hi = mid
                break
            if x < hs:
                hi = mid - 1
            else:
                lo = mid + 1
        if lo - l <= r - lo + 1:
            r = lo - 1
        else:
            l = lo
        s = hs
    a(q(l, l))

tcs = int(input())
for tc in range(tcs):
    main()
