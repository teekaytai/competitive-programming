import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def f(n, k):
    if n < k: return 0, 0
    m = (n + 1) // 2
    if n % 2 == 0:
        x, y = f(m, k)
        # printerr(n, 2 * x, 2 * y + x * m)
        return 2 * x, 2 * y + x * m
    x, y = f(m - 1, k)
    # printerr(n, 2 * x + 1, 2 * y + x * m + m)
    return 2 * x + 1, 2 * y + x * m + m


def main():
    n, k = map(int, input().split())
    print(f(n, k)[1])

tcs = int(input())
for tc in range(tcs):
    main()
