from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 998244353

N = 1000001
*fac, = accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1)
*invfac, = accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD))
invfac.reverse()

def pow(b, p, m):
    r = 1
    while p:
        if p & 1:
            r = (r * b) % m
        p >>= 1
        b = (b * b) % m
    return r

def comb(n, k):
    return fac[n] * invfac[k] * invfac[n-k] % MOD

def main():
    n, m, v = map(int, input().split())
    print(sum(sum((-1)**i * comb(n, i) * (pow((-pow(v-k+1, n-i, MOD) + pow(k, i, MOD)*pow(v, n-i, MOD)) % MOD, m, MOD) - pow((pow(k, i, MOD)*pow(v, n-i, MOD)) % MOD, m, MOD)) % MOD for i in range(1, n+1)) % MOD for k in range(1, v+1)) % MOD)

tcs = int(input())
for tc in range(tcs):
    main()
