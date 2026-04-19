import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [(a[i] - a[-i-1]) % m for i in range(n // 2)]
    b += [0]
    c = [(b[i] - b[i - 1]) % m for i in range(len(b))]
    c.sort()
    s = sum(c)
    t = 0
    ans = m * len(c)
    for i, x in enumerate(c):
        t += x
        s -= x
        ans = min(ans, max(t, (len(c) - i - 1) * m - s))
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
