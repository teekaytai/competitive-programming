import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    def f(lo, hi):
        if lo + 1 == hi:
            return (a[lo],)
        mid = (lo + hi) // 2
        x, y = sorted((f(lo, mid), f(mid, hi)))
        return x + y
    print(*f(0, len(a)))

tcs = int(input())
for tc in range(tcs):
    main()
