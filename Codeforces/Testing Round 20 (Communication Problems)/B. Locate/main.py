import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main(first):
    if first:
        n = int(input())
        *p, = map(int, input().split())
        print(int(p.index(n) < p.index(1)))
    else:
        n, x = map(int, input().split())
        def q(l, r):
            print('?', l, r, flush=True)
            return int(input())
        def a(P):
            print('!', P, flush=True)
        if not x:
            lo = 2
            hi = n
            while lo < hi:
                mid = (lo + hi) // 2
                if q(1, mid) == n - 1:
                    hi = mid
                else:
                    lo = mid + 1
        else:
            lo = 1
            hi = n - 1
            while lo < hi:
                mid = (lo + hi + 1) // 2
                if q(mid, n) == n - 1:
                    lo = mid
                else:
                    hi = mid - 1
        a(lo)


first = input() == 'first'
tcs = int(input())
for tc in range(tcs):
    main(first)
