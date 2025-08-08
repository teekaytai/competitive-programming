import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = map(int, input().split())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    c = [tuple(sorted((x, y))) for x, y in zip(a, b)]
    c.sort()
    t = sum(y - x for x, y in c)
    mn = 10000000000
    for i in range(n - 1):
        d = c[i + 1][0] - c[i][1]
        mn = min(mn, d)
    print(t + max(mn, 0) * 2)

tcs = int(input())
for tc in range(tcs):
    main()
