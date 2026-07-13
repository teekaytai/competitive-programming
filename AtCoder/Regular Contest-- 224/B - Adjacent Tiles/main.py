import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    m = int(n ** 0.5)
    while m * m > n:
        m -= 1
    while (m + 1) ** 2 <= n:
        m += 1
    ans = 2 * m * (m - 1)
    n -= m * m
    if n:
        ans += 2 * n - 1 - (n > m)
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
