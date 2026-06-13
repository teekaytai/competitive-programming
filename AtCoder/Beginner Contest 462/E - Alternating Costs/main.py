import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    a, b, x, y = [int(x) for x in input().split()]
    x = abs(x)
    y = abs(y)
    m = min(x, y)
    ans = m * 2 * min(a, b)
    x -= m
    y -= m
    if x:
        if a <= b:
            x -= 1
            ans += a
        else:
            a, b = b, a
    elif y:
        if b <= a:
            y -= 1
            ans += b
            a, b = b, a
        x, y = y, x
    assert y == 0
    h = x // 2
    res = a * h + b * (x - h)
    res = min(res, 4 * a * h + x % 2 * min(b, a + a + a))
    print(ans + res)

tcs = int(input())
for tc in range(tcs):
    main()
