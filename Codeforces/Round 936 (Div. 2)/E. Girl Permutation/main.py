from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 1000000007
N = 200001
*fac, = accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1)
*invfac, = accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD))
invfac.reverse()

def comb(n, k):
    return fac[n] * invfac[k] * invfac[n-k] % MOD

def main():
    n, m1, m2 = map(int, input().split())
    *p, = map(int, input().split())
    *s, = map(int, input().split())
    if p[0] != 1 or s[-1] != n or p[-1] != s[0]: print(0); return
    t = comb(n-1, s[0]-1) % MOD
    c = p[-1] - 1
    for x in reversed(p):
        if x == p[-1]: continue
        t = t * comb(c - 1, x - 1) * fac[c-x] % MOD
        c = x - 1
    c = n - s[0]
    for x in s:
        if x == s[0]: continue
        t = t * comb(c - 1, n - x) * fac[c-1-n+x] % MOD
        c = n - x
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
