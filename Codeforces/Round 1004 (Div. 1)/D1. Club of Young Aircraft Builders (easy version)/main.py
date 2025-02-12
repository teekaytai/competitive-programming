from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 1000000007
N = 102
*fac, = accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1)
*invfac, = accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD))
invfac.reverse()

def comb(n, k):
    return fac[n] * invfac[k] * invfac[n-k] % MOD

def main():
    n, c, m = map(int, input().split())
    input()
    dp1 = [0] * (m + 1)
    dp2 = [0] * (m + 1)
    dp1[c] = 1
    for h in range(2, n + 1):
        for i in range(c, min(m, h * c) + 1):
            t = 0
            for j in range(c + 1):
                t = (t + comb(c, j) * dp1[i - j]) % MOD
            dp2[i] = t
        dp1, dp2 = dp2, dp1
    print(dp1[m])

tcs = int(input())
for tc in range(tcs):
    main()
