import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    I = sorted(range(n), key=a.__getitem__)
    res = [0] * n
    lo = 0
    hi = 0
    while lo < n:
        while hi < n and a[I[hi]] ^ a[I[lo]] < 4: hi += 1
        b = I[lo:hi]
        c = sorted(b)
        for i, j in zip(b, c):
            res[j] = a[i]
        lo = hi
    print(*res)

tcs = int(input())
for tc in range(tcs):
    main()
