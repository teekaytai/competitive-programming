import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    c = list(zip(a, b))
    lo = 1
    hi = 2 * n
    while lo < hi:
        mid = (lo + hi + 1) // 2
        t0 = 0
        t1 = 0
        p = 1
        for x, y in c:
            v = (x >= mid) + (y >= mid)
            if v == 2: t1 += 1; p = 1
            elif v == 0: t0 += p; p = 0
        if t1 > t0:
            lo = mid
        else:
            hi = mid - 1
    print(lo)

tcs = int(input())
for tc in range(tcs):
    main()
