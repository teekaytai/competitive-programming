import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = [int(x) for x in input().split()]
    a = []
    for _ in range(n):
        l, r = [int(x) for x in input().split()]
        a.append((l, r))
    a.sort()
    INF = 10 ** 9 + 5
    lo = 0
    hi = INF
    while lo < hi:
        mid = (lo + hi + 1) // 2
        c = -INF
        mnr = INF
        i = 0
        for _ in range(k):
            while i < n and a[i][0] < c + mid:
                i += 1
            if i == n:
                hi = mid - 1
                break
            mnr = a[i][1]
            i += 1
            while i < n and a[i][0] < mnr:
                mnr = min(mnr, a[i][1])
                i += 1
            c = mnr
        else:
            lo = mid
    print(lo or -1)

main()
