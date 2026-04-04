from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

def main():
    n, m = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    f = lambda x, y: (x + y) % MOD
    sa = list(accumulate(reversed(a), f, initial=0))
    ssa = list(accumulate(sa, f))[::-1]
    sa.reverse()
    ans = 0
    for i, x in enumerate(b, start=1):
        for j in range(0, n, i):
            k = min(j + i - 1, n)
            ans = (ans + (ssa[j] - ssa[k] - (i - 1) * sa[k]) * x % MOD) % MOD
    print(ans)

main()
