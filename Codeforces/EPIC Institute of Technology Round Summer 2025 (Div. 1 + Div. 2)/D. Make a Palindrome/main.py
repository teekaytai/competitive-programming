import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = map(int, input().split())
    *a, = map(int, input().split())
    if k <= 2:
        print('YES')
        return
    b = sorted(a)
    x = b[k - 2]
    c = [v for v in a if v <= x]
    d = len(c) - (k - 1)
    lo = 0
    hi = len(c) - 1
    while lo < hi:
        if c[lo] == c[hi]:
            lo += 1
            hi -= 1
        elif d == 0:
            print('NO')
            return
        elif c[lo] == x:
            lo += 1
            d -= 1
        elif c[hi] == x:
            hi -= 1
            d -= 1
        else:
            print('NO')
            return
    print('YES')

tcs = int(input())
for tc in range(tcs):
    main()
