import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

from itertools import accumulate
N = 102
*fac, = accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1)
*invfac, = accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD))
invfac.reverse()

def comb(n, k):
    if k > n or k < 0: return 0
    return fac[n] * invfac[k] * invfac[n - k] % MOD

class D:
    def __init__(self, n, v) -> None:
        self.n = n
        self.v = v

    def __add__(self, other):
        return D((self.n + other.n) % MOD, (self.v + other.v + other.n) % MOD)

    def __iadd__(self, other):
        return D((self.n + other.n) % MOD, (self.v + other.v) % MOD)

    def __mul__(self, other):
        return (self.n * other.v % MOD + self.v * other.n % MOD) % MOD

    def __repr__(self) -> str:
        return f'({self.n}, {self.v})'

def main():
    n = int(input())
    s = input()
    n = len(s)
    dp1 = [[D(0, 0)] * (n + 1) for _ in range(n + 1)]
    dp2 = [[D(0, 0)] * (n + 1) for _ in range(n + 1)]
    dp1[0][0] = D(1, 0)
    for i, b in enumerate(s, start=1):
        if b == '(':
            dp1[i][0] = dp1[i - 1][0]
            for j in range(1, n + 1):
                dp1[i][j] = dp1[i - 1][j] + dp1[i - 1][j - 1]
            for j in range(n + 1):
                dp2[i][j] = dp2[i - 1][j]
        else:
            for j in range(n + 1):
                dp1[i][j] = dp1[i - 1][j]
            for j in range(n):
                dp2[i][j] = dp2[i - 1][j] + dp2[i - 1][j + 1] + dp1[i - 1][j + 1]
            dp2[i][n] = dp2[i - 1][n]
        for j in range(n + 1):
            dp1[i - 1][j] += dp2[i - 1][j]
    for j in range(n + 1):
        dp1[n][j] += dp2[n][j]
    dp3 = [[D(0, 0)] * (n + 1) for _ in range(n + 1)]
    dp2[n] = [D(0, 0)] * (n + 1)
    dp2[n][0] = D(1, 0)
    for i in range(n - 1, -1, -1):
        b = s[i]
        if b == ')':
            dp2[i][0] = dp2[i + 1][0]
            for j in range(1, n + 1):
                dp2[i][j] = dp2[i + 1][j] + dp2[i + 1][j - 1]
            dp3[i][0] = dp3[i + 1][0]
            for j in range(1, n + 1):
                dp3[i][j] = dp3[i + 1][j] + dp3[i + 1][j - 1]
        else:
            for j in range(n + 1):
                dp2[i][j] = dp2[i + 1][j]
            for j in range(n):
                dp3[i][j] = dp3[i + 1][j] + dp3[i + 1][j + 1] + dp2[i + 1][j + 1]
            dp3[i][n] = dp3[i + 1][n]
    ans = 0
    p = 0
    q = 0
    for i in range(n - 1):
        if s[i] == '(':
            p += 1
            q = 0
            continue
        for j in range(i + 1, n):
            if s[j] == ')': continue
            t = 0
            for k in range(1, min(p, n - j - 1) + 1):
                # printerr(i, j, k, dp1[i][k], dp3[j + 1][k])
                t = (t + dp1[i][k] * dp3[j + 1][k]) % MOD
            ans = (ans + t) % MOD
        q += 1
    # printerr(dp1)
    print(ans)
    # from itertools import combinations
    # um = 0
    # for k in range(n + 1):
    #     for c in combinations(s, k):
    #         t = ''.join(c)
    #         v = 0
    #         for x in t:
    #             v += 1 if x == '(' else -1
    #             if v < 0:
    #                 break
    #         else:
    #             if v != 0:
    #                 continue
    #             i = t.find(')(')
    #             if i == -1:
    #                 continue
    #             j = t.find('(', i + 2)
    #             um += (k - 2)*(j != -1)
    # printerr(um)

tcs = int(input())
for tc in range(tcs):
    main()
