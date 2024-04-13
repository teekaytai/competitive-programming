import re
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    if all(x==a[0] for x in a): print(-1)
    else:
        r = 0
        mn = 999999
        for x in a:
            if x == a[0]: r += 1
            else: mn = min(r, mn); r = 0
        print(min(mn, r))

tcs = int(input())
for tc in range(tcs):
    main()
