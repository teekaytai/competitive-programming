from math import prod
from itertools import combinations
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    l, r = map(int, input().split())
    ps = [2, 3, 5, 7]
    x = r - l + 1
    for i in range(1, len(ps) + 1):
        for c in combinations(ps, i):
            P = prod(c)
            x += [1, -1][i % 2] * (r // P - (l - 1) // P)
    print(x)

tcs = int(input())
for tc in range(tcs):
    main()
