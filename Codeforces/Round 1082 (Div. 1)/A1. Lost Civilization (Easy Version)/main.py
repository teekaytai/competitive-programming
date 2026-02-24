import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    lo = -2
    hi = -2
    t = 0
    for x in a:
        if x == hi + 1:
            hi = x
        elif lo < x <= hi:
            hi = x
        else:
            t += 1
            lo = x
            hi = x
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
