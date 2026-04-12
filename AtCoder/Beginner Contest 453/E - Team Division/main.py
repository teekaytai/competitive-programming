from heapq import *
from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

N = 200002
fac = list(accumulate(range(1, N+1), lambda p, x: p*x%MOD, initial=1))
invfac = list(accumulate(range(N, 0, -1), lambda p, x: p*x%MOD, initial=pow(fac[-1], -1, MOD)))
invfac.reverse()

def comb(n, k):
    if k > n or k < 0: return 0
    return fac[n] * invfac[k] * invfac[n - k] % MOD

def main():
    n = int(input())
    a = [(*map(int, input().split()), i) for i in range(n)]
    a.sort()
    b = [(r, l, i) for l, r, i in a]
    b.sort(reverse=True)
    ai = 0
    bi = 0
    pqa = []
    pqb = []
    cs = [0] * n
    t = 0
    ans = 0
    for i in range(1, n):
        j = n - i
        while pqa and pqa[0][0] == i:
            k = heappop(pqa)[1]
            cs[k] -= 1
            t -= cs[k] == 0
        while pqb and -pqb[0][0] == j:
            k = heappop(pqb)[1]
            cs[k] -= 1
            t -= cs[k] == 0
        while ai < n and a[ai][0] == i:
            k = a[ai][2]
            heappush(pqa, (a[ai][1] + 1, k))
            cs[k] += 1
            t += cs[k] == 1
            ai += 1
        while bi < n and b[bi][0] == j:
            k = b[bi][2]
            heappush(pqb, (-(b[bi][1] - 1), k))
            cs[k] += 1
            t += cs[k] == 1
            bi += 1
        if t == n and len(pqa) >= i and len(pqb) >= j:
            ans = (ans + comb(len(pqa) + len(pqb) - n, len(pqa) - i)) % MOD
    print(ans)

main()
