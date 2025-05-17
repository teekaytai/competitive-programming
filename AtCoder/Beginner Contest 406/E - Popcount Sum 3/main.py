from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

N = 61
*fac, = accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1)
*invfac, = accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD))
invfac.reverse()

def comb(n, k):
    if k > n or k < 0: return 0
    return fac[n] * invfac[k] * invfac[n - k] % MOD

def main():
    n, k = map(int, input().split())
    bs = f'{n:b}'
    t = 0
    v = 0
    for i, b in enumerate(bs):
        if k > len(bs) - i: break
        if b == '0': continue
        l = len(bs) - i - 1
        t = (t + v * comb(l, k) + (((1 << l)) - 1) * comb(l - 1, k - 1)) % MOD
        k -= 1
        v = (v + (1 << l)) % MOD
    else:
        if k == 0: t = (t + v) % MOD
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
