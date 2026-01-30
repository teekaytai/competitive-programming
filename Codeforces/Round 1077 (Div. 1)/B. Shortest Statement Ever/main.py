import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def MSB(x):
    return 1 << x.bit_length() - 1

def main():
    x, y = [int(x) for x in input().split()]
    o = x & y
    if o == 0:
        print(x, y)
        return
    best = float('inf'), -1, -1
    def f(p, q):
        nonlocal best
        best = min(best, (abs(x - p) + abs(y - q), p, q))
    p = x
    end_p = MSB(x) * 2
    while p <= end_p:
        o = p & y
        if o:
            b = MSB(o)
            q = y - (y & (2 * b - 1)) + ((b - 1) & ~p)
            f(p, q)
            q = y
            while p & q:
                q += q & -q
            f(p, q)
        else:
            f(p, y)
        p = p + (p & -p)
    print(*best[1:])

tcs = int(input())
for tc in range(tcs):
    main()
