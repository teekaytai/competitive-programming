import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)


def main():
    n = int(input())
    *a, = map(int, input().split())
    s = sum(a)
    if s % 2:
        print(-1)
        return
    s //= 2
    x = a[0]
    i = 0
    while x < s:
        i += 1
        x += a[i]
    if x == s:
        print(1)
        print(*a)
        return
    d = x - s
    if d > x - a[i]:
        print(-1)
        return
    b = [*a]
    b[i] -= d
    j = 0
    while d:
        mn = min(d, b[j])
        b[j] -= mn
        d -= mn
        j += 1
    print(2)
    print(*b)
    print(*(p - q for p, q in zip(a, b)))

tcs = int(input())
for tc in range(tcs):
    main()
