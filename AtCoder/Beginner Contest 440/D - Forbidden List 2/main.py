from bisect import *
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, q = [int(x) for x in input().split()]
    a = sorted(int(x) for x in input().split())
    for _ in range(q):
        x, y = [int(x) for x in input().split()]
        s = bisect_left(a, x)
        lo = s - 1
        hi = len(a) - 1
        while lo < hi:
            mid = (lo + hi + 1) // 2
            l = mid - s + 1
            t = a[mid] - x + 1 - l
            if t < y:
                lo = mid
            else:
                hi = mid - 1
        l = lo - s + 1
        print(x + y + l - 1)

main()
