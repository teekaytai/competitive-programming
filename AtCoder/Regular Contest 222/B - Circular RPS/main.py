import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    a, b, c = [int(x) for x in input().split()]
    xs = [c, b, a]
    ans = 0
    if a and b and c:
        x, y, z = sorted((a - 1, b - 1, c - 1))
        ans = min(x + y, (x + y + z) // 2)
    for i in range(3):
        x = xs[i]
        if not x: continue
        j = (i + 1) % 3
        y = xs[j]
        ans = max(ans, min(x - 1, y))
        if not y: continue
        k = (j + 1) % 3
        z = xs[k]
        m = min(z, y - 1)
        ans = max(ans, m + min(x - 1, y - 1 - m))
        if z == 0:
            ans = max(ans, min(x, y) - (y > x))
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
