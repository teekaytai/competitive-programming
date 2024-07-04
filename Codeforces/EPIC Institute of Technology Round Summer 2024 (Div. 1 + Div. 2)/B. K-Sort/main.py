import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    p = -1
    m = 0
    t = 0
    for x in a:
        d = max(p - x, 0)
        m = max(d, m)
        t += d
        p = max(x, p)
    print(t + m)

tcs = int(input())
for tc in range(tcs):
    main()
