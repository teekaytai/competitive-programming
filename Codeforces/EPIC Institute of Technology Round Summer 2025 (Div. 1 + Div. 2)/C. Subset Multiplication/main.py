from math import *
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    x = 1
    for i in range(n - 1):
        x = lcm(x, a[i] // gcd(a[i], a[i + 1]))
    print(x)

tcs = int(input())
for tc in range(tcs):
    main()
