import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = map(int, input().split())
    s = input()
    *a, = map(int, input().split())
    lo = 0
    hi = max(a)
    while lo < hi:
        mid = (lo + hi) // 2
        kk = k
        b = False
        for c, x in zip(s, a):
            if c == 'R':
                if x > mid: b = False
            elif x > mid:
                kk -= not b
                if kk < 0: lo = mid + 1; break
                b = True
        else:
            hi = mid
    print(lo)

tcs = int(input())
for tc in range(tcs):
    main()
