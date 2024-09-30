import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def f(x):
    s = int(x**.5)
    return s if s*s<=x else s-1

def main():
    k = int(input())
    # for i in range(1, 21):
    #     a = [1] * i
    #     for j in range(1, i+1):
    #         for k in range(j, i+1, j):
    #             a[k-1] = 1 - a[k-1]
    #     print(i, sum(a))
    # exit()
    if k == 1: print(2); return
    lo = 1
    hi = k * k
    while lo < hi:
        mid = (lo + hi) // 2
        if mid - f(mid) < k:
            lo = mid + 1
        else:
            hi = mid
    print(lo)

tcs = int(input())
for tc in range(tcs):
    main()
