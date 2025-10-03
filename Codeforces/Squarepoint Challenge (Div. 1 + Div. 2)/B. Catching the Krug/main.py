import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, r, c, R, C = map(int, input().split())
    dr = abs(r - R)
    dc = abs(c - C)
    # if dr > dc:
    #     dr, dc = dc, dr
    #     r, c = c, r
    #     R, C = C, R
    x = R if r < R else n - R
    y = C if c < C else n - C
    # x = max(R, n - R)
    # y = max(C, n - C)
    # printerr(x, y, dr, dc)
    print(max(max(x, dc) if dr else dc, max(y, dr) if dc else dr))
    # print(max(min(abs(R - x), abs(C - y)) for x, y in [(0, c), (n, c), (r, 0), (r, n)]))

tcs = int(input())
for tc in range(tcs):
    main()
