import math
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    r = int(input())
    x = r
    y = 1
    t = 0
    for x in range(0, r+1):
        t += math.ceil(((r+1)**2-x*x)**.5) - math.ceil((r*r-x*x)**.5)
    print(t*4-4)

tcs = int(input())
for tc in range(tcs):
    main()
