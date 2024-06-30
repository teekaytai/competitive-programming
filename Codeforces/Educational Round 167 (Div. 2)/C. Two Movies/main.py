import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    x, y = 0, 0
    s = [0, 0, 0]
    for p, q in zip(a, b):
        if p != q:
            if p > q: x += p
            else: y += q
        else: s[p] += 1
    x, y = sorted((x, y))
    m = min(y - x, s[1])
    x += m
    s[1] -= m
    m = min(y - x, s[-1])
    y -= m
    s[-1] -= m
    if s[1] or s[-1]:
        t = s[1] - s[-1]
        print(x + t//2)
    else:
        print(x)

tcs = int(input())
for tc in range(tcs):
    main()
