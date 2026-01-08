import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m, k = [int(x) for x in input().split()]
    # from itertools import product
    # for n, m, k in product(range(5, 6), range(1, 11), range(1, 6)):
    #     if k > n: continue
    l = k - 1
    r = n - k
    if l < r:
        l, r = r, l
    ans = 0
    for i in range(1, l + 1):
        d = i - 1 + i
        # printerr(i, d)
        if d <= m:
            t = i + min(m - d, r, i)
            ans = max(ans, t)
    assert ans + 1 <= n
    print(ans + 1)
    # printerr(n, m, k, ans + 1)

tcs = int(input())
for tc in range(tcs):
    main()
