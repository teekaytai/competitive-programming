from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or len(args) == 1 and args[0] or args

MOD = 998244353
N = 100002
*fac, = accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1)
*invfac, = accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD))
invfac.reverse()

def comb(n, k):
    return fac[n] * invfac[k] * invfac[n-k] % MOD

def modinv(x, mod=MOD):
    return x if x <= 1 else mod - mod // x * modinv(mod % x, mod) % mod

def moddiv(a, b, mod=MOD):
    return a * modinv(b, mod) % mod

def catalan(n):
    return moddiv(comb(2*n, n), (n + 1))

def f(a):
    s = []
    ls = []
    t = 1
    for i, x in enumerate(a):
        if not x: continue
        if x == -1: s.append(i); ls.append(0)
        else:
            j = s.pop()
            l = ls.pop()
            t = (t * catalan((i - j - 1 - l) // 2)) % MOD
            if ls: ls[-1] += i - j + 1
    return t

def main():
    n = int(input())
    a = [-1] + [0] * (2 * n) + [1]
    ans = []
    ans.append(f(a))
    for _ in range(n):
        l, r = map(int, input().split())
        a[l] = -1
        a[r] = 1
        ans.append(f(a))
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
