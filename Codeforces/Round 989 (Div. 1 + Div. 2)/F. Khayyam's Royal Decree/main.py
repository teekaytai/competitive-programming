from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 998244353

N = 500001
*fac, = accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1)
*invfac, = accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD))
invfac.reverse()

def comb(n, k):
    return fac[n] * invfac[k] * invfac[n-k] % MOD

def modinv(x, mod=MOD):
    return pow(x, -1, mod)
    # return x if x <= 1 else mod - mod // x * modinv(mod % x, mod) % mod

def moddiv(a, b, mod=MOD):
    return a * modinv(b, mod) % mod

def f(x1, y1, x2, y2):
    if x1 > x2 or y1 > y2: return 0
    dx = x2 - x1
    dy = y2 - y1
    return comb(dx + dy, dx)

def main():
    n, m, k = map(int, input().split())
    a = [(0, 0), (n, m)]
    for _ in range(k):
        x, y = map(int, input().split())
        a.append((n - x, m - y))
    a.sort(key=sum)
    b = [0] * len(a)
    b[-1] = 1
    for i in range(len(a) - 2, -1, -1):
        for j in range(i + 1, len(a)):
            b[i] = (b[i] + f(*a[i], *a[j]) * b[j] % MOD) % MOD
    t = 0
    for (x,y), w in zip(a,b):
        t = (t + (2*x + y) * f(*a[0], x, y) % MOD * w % MOD) % MOD
    print(moddiv(t, comb(n+m, n)))

tcs = int(input())
for tc in range(tcs):
    main()
