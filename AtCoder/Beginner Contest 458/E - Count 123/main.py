import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

from itertools import accumulate
N = 2000005
fac = list(accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1))
invfac = list(accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD)))
invfac.reverse()

def comb(n, k):
    if k > n or k < 0: return 0
    return fac[n] * invfac[k] * invfac[n - k] % MOD

def main():
    x, y, z = [int(x) for x in input().split()]
    t = 0
    for i in range(1, min(x, y) + 1):
        t += comb(y + 1, i) * comb(i - 1 + x - i, i - 1) % MOD * comb(z + y + 1 - i - 1, z) % MOD
        t %= MOD
    print(t)

main()
