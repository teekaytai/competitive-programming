from math import gcd
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    a, b, k = map(int, input().split())
    print(1 + (max(a, b) // gcd(a, b) > k))

tcs = int(input())
for tc in range(tcs):
    main()
