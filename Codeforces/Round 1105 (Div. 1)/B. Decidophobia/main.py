from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, d = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    a += a
    ps = list(accumulate(a, initial=0))
    ans = 0
    for i in range(n):
        lo = (i - d) % n
        hi = lo + 2 * d
        s = 2 * d * a[i] - (ps[hi + 1] - ps[lo] - a[i])
        ans += max(s, 0)
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
