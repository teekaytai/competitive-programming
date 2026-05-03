from itertools import combinations_with_replacement
from itertools import combinations
import bisect
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, q = [int(x) for x in input().split()]
    p = [int(x) for x in input().split()]
    p.append(n + 1)
    a = [-1] * n
    ds = [0]
    l = 0
    c = 0
    for i, x in enumerate(p):
        if i > 0 and x > p[i - 1]:
            while l < c:
                a[l] = i - 1
                l += 1
            c = i
            ds.append(c)
        if i == n: break
        while l < c:
            if p[l] < x:
                break
            a[l] = i - 1
            l += 1
    aa = [a]
    le = 2
    while le < n:
        a1 = aa[-1]
        a2 = [a1[a1[i]] for i in range(n)]
        aa.append(a2)
        le *= 2
    le //= 2
    for _ in range(q):
        l, r = [int(x) for x in input().split()]
        l -= 1; r -= 1
        R = ds[bisect.bisect_right(ds, r) - 1]
        if R <= l:
            print(1)
            continue
        c = ds[bisect.bisect_right(ds, l)] - 1
        ans = 2
        i = len(aa) - 1
        x = le
        while x > 0:
            c2 = aa[i][c]
            if c2 != -1 and c2 < R:
                ans += x
                c = c2
            x //= 2
            i -= 1
        print(ans)

main()
