from math import lcm
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    l = lcm(*a)
    b = [l//x for x in a]
    t = sum(b)
    if all(x*y>t for x,y in zip(a,b)):print(*b)
    else: print(-1)

tcs = int(input())
for tc in range(tcs):
    main()
