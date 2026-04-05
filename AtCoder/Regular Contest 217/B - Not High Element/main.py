from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

N = 1000002
fac = list(accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1))
invfac = list(accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD)))
invfac.reverse()

POW2 = [1]

for i in range(500005):
    POW2.append(POW2[-1] * 2 % MOD)

def comb(n, k):
    if k > n or k < 0: return 0
    return fac[n] * invfac[k] * invfac[n - k] % MOD

def main():
    n, k = [int(x) for x in input().split()]
    m = n - k
    facm = fac[m]
    a = [int(x) for x in input().split()]
    seen = [0] * (n + 1)
    ans = 0
    mx = -1
    for x in a:
        if x < mx:
            ans = (ans + POW2[x - 1] * facm) % MOD
        seen[x] = 1
        mx = max(mx, x)
    for i in range(1, n + 1):
        if seen[i]: continue
        if i < mx:
            ans = (ans + POW2[i - 1] * facm) % MOD
        else:
            ans = (ans + (facm - comb(m, n - i + 1) * fac[n - i] % MOD * fac[i - k - 1] % MOD) * POW2[i - 1]) % MOD
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
