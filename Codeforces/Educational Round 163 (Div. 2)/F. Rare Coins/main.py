from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 998244353

def main():
    n, q = map(int, input().split())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    *ap, = accumulate(a, initial=0)
    *bp, = accumulate(b, initial=0)
    G = ap[-1]
    S = bp[-1]
    *facs, = accumulate(range(1, S+1), lambda p,x:p*x%MOD, initial=1)
    *invfacs, = accumulate(range(S, 0, -1), lambda p,x:p*x%MOD, initial=pow(facs[-1], -1, MOD))
    invfacs.reverse()
    x = pow(2, -S, MOD)
    c = [facs[S] * invfacs[i] * invfacs[S-i] * x % MOD for i in range(S+1)]
    *cp, = accumulate(c, lambda t,x: (t+x)%MOD, initial=0)
    ans = []
    for _ in range(q):
        l, r = map(int, input().split())
        dg = G - 2*(ap[r] - ap[l-1])
        s = S - (bp[r] - bp[l-1])
        ans.append((cp[-1] - cp[min(S+1, max(dg+s+1, 0))]) % MOD)
    print(*ans)

main()
