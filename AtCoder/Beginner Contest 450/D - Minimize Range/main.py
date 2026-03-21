from itertools import pairwise
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = [int(x) for x in input().split()]
    a = sorted(int(x) % k for x in input().split())
    if n == 1:
        print(0)
        return
    ans = min(min(x + k - y for x, y in pairwise(a)), a[-1] - a[0])
    print(ans)

main()
