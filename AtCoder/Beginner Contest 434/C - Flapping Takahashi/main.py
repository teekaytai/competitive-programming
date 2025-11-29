import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, h = map(int, input().split())
    pt = 0
    ph = h
    pl = h
    can = True
    for _ in range(n):
        t, l, u = map(int, input().split())
        dt = t - pt
        H = ph + dt
        L = max(pl - dt, 1)
        ph = min(H, u)
        pl = max(L, l)
        if pl > ph:
            can = False
        pt = t
    print('Yes' if can else 'No')

tcs = int(input())
for tc in range(tcs):
    main()
