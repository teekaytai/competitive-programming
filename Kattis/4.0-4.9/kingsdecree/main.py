import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n = int(input())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    t = sum(a) - sum(b)
    lo = min(b)
    hi = max(a)
    while lo < hi:
        mid = (lo + hi + 1) // 2
        s = sum(max(mid - x, 0) for x in b)
        if s <= t:
            lo = mid
        else:
            hi = mid - 1
    print(lo)
