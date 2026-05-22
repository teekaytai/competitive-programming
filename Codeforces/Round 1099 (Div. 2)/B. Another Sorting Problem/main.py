import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    mx = -1
    d = 0
    for x in a:
        d = max(d, mx - x)
        mx = max(mx, x)
    p = -1
    for x in a:
        if x < p:
            x += d
            if x < p:
                print('NO')
                return
        p = x
    print('YES')

tcs = int(input())
for tc in range(tcs):
    main()
