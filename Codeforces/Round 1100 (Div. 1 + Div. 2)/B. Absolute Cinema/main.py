import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    mx = 0
    t = 0
    for x, y in zip(a, b):
        t += max(x, y)
        mx = max(mx, min(x, y))
    print(mx + t)

tcs = int(input())
for tc in range(tcs):
    main()
