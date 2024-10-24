from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().strip()
# printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 998244353

N = 200002
*fac, = accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1)
*invfac, = accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD))
invfac.reverse()

def comb(n, k):
    return fac[n] * invfac[k] * invfac[n-k] % MOD

def main():
    n = int(input())
    if n == 1:
        print(1 if int(input()) == 0 else 0)
        return
    cs = [0] * (n + 1)
    for x in map(int, input().split()):
        cs[x] += 1
    dp = [0] * (cs[0] + 1)
    ep = [0] * (cs[0] + 1)
    for i in range(cs[0], -1, -1):
        v = comb(cs[0], i)
        dp[i] = ((dp[i + 1] if i < cs[0] else 0) + i * v) % MOD
        ep[i] = ((ep[i + 1] if i < cs[0] else 0) + v) % MOD
    # printerr(dp)
    # printerr(ep)
    for i in range(1, n+1):
        x = cs[i]
        if x == 0:
            print(dp[0] * pow(2, sum(cs[i+1:]), MOD) % MOD)
            return
        dp2 = [0] * min(len(dp), x + 1)
        ep2 = [0] * min(len(ep), x + 1)
        s = 0
        for i in range(x, -1, -1):
            v = comb(x, i)
            s += v
            if i >= len(dp2): continue
            ep2[i] = ep[i] * s % MOD
            dp2[i] = ((dp[i] + ep[i] * i) * v % MOD + (dp[i] - (dp[i+1] if i < len(dp)-1 else 0) % MOD + i * (ep[i] - (ep[i+1] if i < len(ep)-1 else 0))) * (s - v) % MOD) % MOD
            if i < len(dp2) - 1:
                dp2[i] = (dp2[i] + dp2[i + 1]) % MOD
        dp = dp2
        ep = ep2
        # printerr(dp2, ep2)

# def temp():
#     from collections import Counter
#     n = int(input())
#     *a, = map(int, input().split())
#     mx = max(a)
#     t = 0
#     for i in range(1 << n):
#         c = Counter()
#         j = 0
#         while i:
#             if i&1:c[a[j]] += 1
#             i >>= 1
#             j += 1
#         m = 999999
#         for i in range(mx + 1):
#             m = min(m, c[i])
#             t += m
#     print(t)


tcs = int(input())
for tc in range(tcs):
    main()
    # temp()
