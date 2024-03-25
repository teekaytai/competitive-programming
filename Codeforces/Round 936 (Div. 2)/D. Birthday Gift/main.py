import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, x = map(int, input().split())
    *a, = map(int, input().split())
    mx = -1
    mask = x
    def f(y):
        c = 0
        k = 0
        for v in a:
            c ^= v
            if (c & ~y) == 0:
                c = 0
                k += 1
        return k if c == 0 else -1
    mx = max(mx, f(x))
    while mask:
        b = mask & -mask
        mask -= b
        y = (x - b) | (b - 1)
        mx = max(mx, f(y))
    print(mx)

tcs = int(input())
for tc in range(tcs):
    main()
