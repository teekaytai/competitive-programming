from collections import Counter
from fractions import Fraction
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = sorted(map(int, input().split()), key=abs)
    c = Counter(a)
    can = len(c) == 1
    if len(c) == 2:
        x, y = c.keys()
        can |= x == -y and c[x] in (n // 2, (n + 1) // 2)
    r = Fraction(a[1], a[0])
    print('Yes' if can or all(Fraction(a[i], a[i - 1]) == r for i in range(2, n)) else 'No')

tcs = int(input())
for tc in range(tcs):
    main()
