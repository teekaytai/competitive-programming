from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    ps = list(accumulate(a[::-1], initial=0))
    ans = -ps[n-1]
    c = a[0]
    for i in range(1, n):
        ans = max(ans, c - ps[n-i-1])
        c += abs(a[i])
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
