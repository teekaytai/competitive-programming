from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353
N = 5001
fac = list(accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1))
invfac = list(accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD)))
invfac.reverse()

def comb(n, k):
    if k > n or k < 0: return 0
    return fac[n] * invfac[k] * invfac[n - k] % MOD

def main():
    n, q = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    fps = list(accumulate((int(x == -1) for x in a), initial=0))
    pmn = list(accumulate((x if x != -1 else n for x in a), min, initial=n))
    smn = list(accumulate((x if x != -1 else n for x in reversed(a)), min, initial=n))
    smn.reverse()
    gone = [1] * (n + 1)
    gone[0] = 0
    for x in a:
        if x != -1:
            gone[x + 1] = 0
    gone[:] = accumulate(gone)
    dp = [[0] * (fps[-1] + 1) for _ in range(n + 1)]
    for mex in range(1, n + 1):
        for j in range(fps[-1] + 1):
            dp[mex][j] = (dp[mex - 1][j] + (comb(j, gone[mex]) * fac[gone[mex]] % MOD * fac[fps[-1] - gone[mex]] % MOD if j >= gone[mex] else 0)) % MOD
    for _ in range(q):
        l, r = [int(x) for x in input().split()]
        l -= 1; r -= 1
        print(dp[min(pmn[l], smn[r + 1])][fps[r + 1] - fps[l]])

main()
