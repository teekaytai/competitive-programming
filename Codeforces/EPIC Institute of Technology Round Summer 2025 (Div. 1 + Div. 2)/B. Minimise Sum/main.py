import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    ans = a[0] + a[1]
    mn = 10000000
    t = 0
    for i, x in enumerate(a):
        mn = min(mn, x)
        t += mn
        if i > 0:
            ans = min(ans, t)
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
