import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    INF = 10 ** 15
    n = int(input())
    s = input()
    a = [int(x) for x in input().split()]
    c = [int(x) for x in input().split()]
    FLAG = n
    j = FLAG
    p = -INF
    lo = hi = 0
    for i, (b, x, y) in enumerate(zip(s, a, c)):
        if y < p:
            print('No')
            return
        if b == '1':
            lo += x
            hi += x
        else:
            j = i
            a[j] += max(p, y) - hi
            lo = -INF
            hi = max(p, y)
        if y > p:
            if y < lo or y > hi:
                print('No')
                return
            if j != FLAG:
                a[j] -= hi - y
                j = FLAG
            lo = y
            hi = y
            p = y
        else:
            if p < lo:
                print('No')
                return
            if j != FLAG and p < hi:
                a[j] -= hi - p
                lo = -INF
                hi = p
    print('Yes')
    print(*a)

tcs = int(input())
for tc in range(tcs):
    main()
