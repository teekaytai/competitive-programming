from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

N = 1000002
fac = list(accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1))
invfac = list(accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD)))
invfac.reverse()

def comb(n, k):
    if k > n or k < 0: return 0
    return fac[n] * invfac[k] * invfac[n - k] % MOD

def modsum(a, mod=MOD):
    t = 0
    for x in a:
        t = (t + x) % mod
    return t

def modinv(x, mod=MOD):
    return x if x <= 1 else mod - mod // x * modinv(mod % x, mod) % mod
    # return pow(x, -1, mod)  # Works for non-prime mod and works for x > mod

def moddiv(a, b, mod=MOD):
    return a * modinv(b % mod, mod) % mod

def modpow(b, p, mod=MOD):
    r = 1
    while p:
        if p & 1:
            r = (r * b) % mod
        b = (b * b) % mod
        p >>= 1
    return r

def f(x, y):
    return moddiv(modsum(moddiv(comb(y, i), x + i) for i in range(y + 1)), modpow(2, y))

def main():
    n = int(input())
    a = []
    mx = 0
    for _ in range(n):
        l, r = [int(x) for x in input().split()]
        a.append(l); a.append(r)
        mx = max(mx, l, r)
    cs = [0] * 6
    ts = []
    for i in range(0, 2 * n, 2):
        l, r = sorted((a[i], a[i + 1]), reverse=True)
        if l == mx:
            t = (r < mx) + (r < mx - 1)
        elif l == mx - 1:
            t = 3 if r == mx - 1 else 4
        else:
            t = 5
        cs[t] += 1
        ts.append(t)
    inv2 = modinv(2)
    ans = []
    if cs[0]:
        x = cs[0]
        y = cs[1] + cs[2]
        xp = inv2 * f(x, y) % MOD
        yp = inv2 * f(x + 1, y - 1) % MOD if y else 0
        for i in range(n):
            if ts[i] == 0:
                ans.append(xp); ans.append(xp)
            elif ts[i] == 1 or ts[i] == 2:
                ans.append(yp if a[2*i] == mx else 0); ans.append(yp if a[2*i+1] == mx else 0)
            else:
                ans.append(0); ans.append(0)
    else:
        x = cs[1]
        y = cs[2]
        z = cs[3]
        w = cs[4]
        p = modpow(inv2, x+y)
        temp = f(2*x+y+z, w)
        xp = p * temp % MOD
        yp = inv2 * f(1, x+y-1) % MOD
        kp = (xp + yp) % MOD
        zp = p * inv2 * temp % MOD
        wp = p * inv2 * f(2*x+y+z+1, w-1) % MOD if w else 0
        for i in range(n):
            l = a[2*i]
            r = a[2*i+1]
            if ts[i] == 1:
                ans.append(kp if l == mx else xp)
                ans.append(kp if r == mx else xp)
            elif ts[i] == 2:
                ans.append(kp if l == mx else 0)
                ans.append(kp if r == mx else 0)
            elif ts[i] == 3:
                ans.append(zp)
                ans.append(zp)
            elif ts[i] == 4:
                ans.append(wp if l == mx - 1 else 0)
                ans.append(wp if r == mx - 1 else 0)
            else:
                ans.append(0); ans.append(0)
    print(*ans)

main()
