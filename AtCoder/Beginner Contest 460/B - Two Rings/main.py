import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    x1, y1, r1, x2, y2, r2 = [int(x) for x in input().split()]
    print('Yes' if (r1 - r2) ** 2 <= (x1 - x2) ** 2 + (y1 - y2) ** 2 <= (r1 + r2) ** 2 else 'No')

tcs = int(input())
for tc in range(tcs):
    main()
