import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    if n < 4:
        a = [
            [],
            [1, 1],
            [1, 2, 1, 2],
            [1, 3, 1, 2, 3, 2]
        ][n]
    elif n % 2 == 0:
        a = [
            *range(n, 0, -2),
            n - 1,
            *range(2, n + 2, 2),
            *range(n - 3, 1, -2),
            n - 1,
            1,
            *range(3, n - 2, 2),
            1
        ]
    else:
        a = [
            *range(n, 1, -2),
            n - 1,
            1,
            *range(3, n + 1, 2),
            *range(n - 3, 2, -2),
            n - 1,
            1 + (n % 4 == 1),
            2 - (n % 4 == 1),
            *range(4, n - 2, 2),
            2
        ]
    print(*a)


tcs = int(input())
for tc in range(tcs):
    main()
