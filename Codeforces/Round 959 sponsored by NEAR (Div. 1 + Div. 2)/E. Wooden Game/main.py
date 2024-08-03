from heapq import *
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    a = []
    for _ in range(n):
        a.append(-int(input()))
        input()
    heapify(a)
    b = 1 << ((-a[0]).bit_length() - 1)
    x = 0
    while b:
        while -a[0] < b:
            b >>= 1
        if not b: break
        if -a[0] >= b * 2:
            x |= b * 2 - 1
            break
        x |= b
        heapreplace(a, -(-a[0] - b))
        b >>= 1
    print(x)

tcs = int(input())
for tc in range(tcs):
    main()
