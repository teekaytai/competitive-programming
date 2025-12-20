import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    INF = 10000000000
    n = int(input())
    a = [int(x) for x in input().split()]
    if n == 1:
        print(0)
        return
    p = a[0]
    l = p
    r = a[1]
    t = 0
    for i in range(1, n):
        x = a[i]
        d = INF if i == n - 1 else a[i + 1] - x
        if d <= x - r:
            l = x
            r = x + d
        else:
            t += 1
            l, r = x + (x - r), min(x + d, x + (x - l))
        p = x
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
