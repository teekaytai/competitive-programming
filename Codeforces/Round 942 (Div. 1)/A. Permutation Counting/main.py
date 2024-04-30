import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    *a, = map(int, input().split())
    lo = min(a)
    hi = (sum(a) + k + n - 1) // n
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if sum(max(mid - x, 0) for x in a) <= k:
            lo = mid
        else:
            hi = mid - 1
    t = sum(x > lo for x in a) + k - sum(max(lo - x, 0) for x in a)
    print((lo - 1) * n + 1 + t if lo > 0 else 0)

tcs = int(input())
for tc in range(tcs):
    main()
