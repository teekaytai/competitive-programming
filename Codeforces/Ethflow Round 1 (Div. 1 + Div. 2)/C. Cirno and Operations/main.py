from itertools import pairwise
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    if n == 1: print(a[0]); return
    mx = sum(a)
    while len(a) > 1:
        a, b = [y - x for x, y in pairwise(a)], [y - x for x, y in pairwise(a[::-1])]
        mx = max(mx, sum(a), sum(b))
    print(mx)

tcs = int(input())
for tc in range(tcs):
    main()
