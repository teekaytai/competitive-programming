import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, m = map(int, input().split())
    y, x, t = 0, 0, 0
    for r in range(1, n+1):
        for c, p in enumerate(input(), start=1):
            y += r * (p=='#')
            x += c * (p=='#')
            t += (p=='#')
    print(y//t, x//t)

tcs = int(input())
for tc in range(tcs):
    main()
