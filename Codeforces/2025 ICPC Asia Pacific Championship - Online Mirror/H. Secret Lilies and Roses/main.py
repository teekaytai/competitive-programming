import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    def t(i):
        print('type', i, flush=True)
        return input()
    def m(i):
        if i < 1 or i > n: return 0
        print('multi', i, flush=True)
        return int(input())
    def a(i):
        print('answer', i, flush=True)

    lo = 0
    hi = n
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if t(mid) == 'lily':
            hi = mid - 1
        else:
            lo = mid
    x = m(lo)
    y = m(lo - 1)
    z = m(lo + 1)
    l = y - x
    r = z - x
    a(lo - l + r)


tcs = int(input())
for tc in range(tcs):
    main()
