from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 1000000007
N = 100002
fac = list(accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1))
invfac = list(accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD)))
invfac.reverse()

def comb(n, k):
    if k > n or k < 0: return 0
    return fac[n] * invfac[k] * invfac[n - k] % MOD

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = []
    c = 0
    for i in range(n - 1, -1, -1):
        x = a[i]
        if x:
            c |= x
            for j in range(i - 1, -1, -1):
                a[j] = (a[j] - x * comb(i + 1, j + 1)) % MOD
        ans.append(c)
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
