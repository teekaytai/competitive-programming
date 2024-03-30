from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 998244353

N = 1000000
*fac, = accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1)
*invfac, = accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD))
invfac.reverse()

def comb(n, k):
    return fac[n] * invfac[k] * invfac[n-k] % MOD

def main():
    l, n = map(int, input().split())
    s = l - n - n
    x = 0
    for i in range(s//2+1):
        x = (x + comb(i+n-1, i) * comb(s-i*2+n, n)) % MOD
    print(2 * (comb(l, 2*n) - x) % MOD)

tcs = int(input())
for tc in range(tcs):
    main()
