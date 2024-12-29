import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    s = sum(a)
    l = h = 0
    t = 0
    for x in a:
        l2 = l + x
        h2 = h + x
        if l2 > s:
            l = l2 - l
            h = s
            t += 1
        elif h2 < 0:
            l = 0
            h = h2 + s - h
            t += 1
        else:
            l = max(l2, 0)
            h = min(h2, s)
        # printerr(l, h, x)
    print(len(a) + t + (h < s))

tcs = int(input())
for tc in range(tcs):
    main()
