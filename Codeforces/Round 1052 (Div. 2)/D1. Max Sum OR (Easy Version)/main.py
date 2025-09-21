import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    L, R = map(int, input().split())
    r = R
    a = list(range(r + 1))
    while r > 0:
        p = 1 << (r.bit_length() - 1)
        k = p - (r - p) - 1
        a[k:r+1] = a[k:r+1][::-1]
        r = k - 1
    print(sum(x | y for x, y in zip(a, range(R + 1))))
    print(*a)

tcs = int(input())
for tc in range(tcs):
    main()
