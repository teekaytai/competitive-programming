from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 1000000007

N = 400002
*fac, = accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1)
*invfac, = accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD))
invfac.reverse()

def comb(n, k):
    if k > n or k < 0: return 0
    return fac[n] * invfac[k] * invfac[n - k] % MOD

def modinv(x, mod=MOD):
    return x if x <= 1 else mod - mod // x * modinv(mod % x, mod) % mod

def moddiv(a, b, mod=MOD):
    return a * modinv(b, mod) % mod

def f(n, m, x):
    t = 0
    for i in range((m // x) + 1):
        t = (t + (-1)**i * comb(n, i) * comb(m - i * (x + 1) + n - 1, n - 1)) % MOD
    return t

def main():
    n, m = map(int, input().split())
    t = 0
    for x in range(1, m + 1):
        p = f(n - 1, m - x, x)
        q = f(n - 2, m - 2 * x, x)
        t = (t + x * p + x * (n - 1) * q - moddiv(m - x, n - 1) * p - (x + m - 2 * x) * q) % MOD
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
