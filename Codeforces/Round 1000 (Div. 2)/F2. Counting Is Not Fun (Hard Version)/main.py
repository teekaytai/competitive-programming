from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or len(args) == 1 and args[0] or args

MOD = 998244353
N = 700002
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

def main():
    n = int(input())
    a = [False] * (2*n+2)
    a[0] = True
    a[-1] = True
    ans = []
    ps = list(range(-1, 2*n+1))
    ns = list(range(1, 2*n+3))
    szi = [0] * (2*n+2)
    szs = [2*n]
    t = catalan(n)
    ans.append(t)
    for _ in range(n):
        l, r = map(int, input().split())
        a[l] = True
        a[r] = True
        S = szs[szi[l]]
        s = 1
        x = ns[l]
        y = ns[r]
        while not a[x] and not a[y]:
            x = ns[x]
            y = ns[y]
            s += 1
        if not a[x]:
            y = ps[l]
            while not a[x] and not a[y]:
                x = ns[x]
                y = ps[y]
                s += 1
        p = ps[l]
        q = ns[r]
        ns[p] = q
        ps[q] = p
        if a[x]:
            c = l
            szi[c] = len(szs)
            while c != r:
                c = ns[c]
                szi[c] = len(szs)
            szs[szi[p]] = S-s-1
            szs.append(s-1)
        else:
            c = p
            szi[c] = len(szs)
            while not a[c]:
                c = ps[c]
                szi[c] = len(szs)
            c = q
            szi[c] = len(szs)
            while not a[c]:
                c = ns[c]
                szi[c] = len(szs)
            szs[szi[l]] = S-s-1
            szs.append(s-1)
        t = moddiv(t, catalan(S//2)) * catalan(szs[szi[l]]//2) % MOD * catalan(szs[szi[p]]//2) % MOD
        ans.append(t)
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
