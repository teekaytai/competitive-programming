import sys

input = lambda: sys.stdin.readline().strip()

n, b = map(int, input().split())
while n > 0:
    a = [int(input()) for _ in range(n)]
    lo = 1
    hi = max(a)
    while lo < hi:
        mid = (lo + hi) // 2
        t = sum((x + mid - 1) // mid for x in a)
        if t > b:
            lo = mid + 1
        else:
            hi = mid
    print(lo)

    input()
    n, b = map(int, input().split())
