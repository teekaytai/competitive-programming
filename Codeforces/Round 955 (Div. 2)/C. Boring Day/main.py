import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, l, r = map(int, input().split())
    *a, = map(int, input().split())
    c = 0
    lo = 0
    t = 0
    for i, x in enumerate(a):
        c += x
        while c > r:
            c -= a[lo]
            lo += 1
        if l <= c <= r:
            t += 1
            c = 0
            lo = i + 1
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
